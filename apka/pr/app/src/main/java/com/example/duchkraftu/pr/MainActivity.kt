package com.example.duchkraftu.pr

import android.bluetooth.BluetoothAdapter
import android.bluetooth.BluetoothDevice
import android.bluetooth.BluetoothServerSocket
import android.bluetooth.BluetoothSocket
import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.*
import java.io.InputStream
import java.io.OutputStream
import java.util.*

class MainActivity : AppCompatActivity() {

    var toSend: String ="00000000"
    var right: Int= 0
    var left: Int= 0
    val devices: Array<BluetoothDevice> = emptyArray()
    lateinit var InputSTRM: InputStream
    lateinit var OutputSTRM: OutputStream
    val OnItemClick = AdapterView.OnItemClickListener {
        parent, view: View,position: Int, id: Long ->
        val text = parent.getItemAtPosition(position).toString()
        val toast= Toast.makeText(this, text, Toast.LENGTH_SHORT)
        toast.show()
        val btSocket = devices[position].createRfcommSocketToServiceRecord(devices[position].uuids[0].uuid)
        btSocket.connect()
        InputSTRM=btSocket.inputStream
        OutputSTRM=btSocket.outputStream
        val intent = Intent(this, TerminalActivity::class.java)
        //intent.putExtra("device",btSocket)
        //startActivity(intent)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val lv = findViewById<View>(R.id.LV) as ListView
        val bt = BluetoothAdapter.getDefaultAdapter()
        toSend = "00000000"
        right = 0
        left = 0
        if (bt == null) {
            val text = "no bluetooth capabilities"
            val toast = Toast.makeText(this, text, Toast.LENGTH_SHORT)
            toast.show()
        } else {
            val pairedDevices = bt.bondedDevices
            val names: Array<String> = emptyArray()
            for (device in pairedDevices) {
                names.plus(device.name)
                devices.plus(device)
            }
            if (names.size <= 0) {
                Toast.makeText(this, "no devices", Toast.LENGTH_SHORT).show()
            }
            val array_adapter = ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, names)
            lv.setAdapter(array_adapter)
            lv.setOnItemClickListener(OnItemClick)
        }
    }
        fun setString(right: Int,left: Int): String{
            var result: String =""
            if(right<0) result+="0" else result +='1'
            if(right>=100) result+=right.toString()
            else if(right >=10) result+='0'+right.toString()
            else result+="00"+right.toString()
            if(left<0) result+="0" else result+='1'
            if(left>=100) result+=left.toString()
            else if(left>=10) result+="0"+left.toString()
            else result+="00"+left.toString()
            return result
        }

        fun Rightbutton(view: View){
            right += 20
            toSend=setString(right,left)
            OutputSTRM.write(toSend.toByteArray())
        }

        fun Leftbutton(view: View){
            left+=20
            toSend=setString(right,left)
            OutputSTRM.write(toSend.toByteArray())
        }
        fun Forwardbutton(view: View){
            right+=10
            left+=10
            toSend=setString(right, left)
            OutputSTRM.write(toSend.toByteArray())
        }
        fun Backbutton(view: View){
            right-=10
            left-=10
            toSend=setString(right, left)
            OutputSTRM.write(toSend.toByteArray())
        }
        fun Stopbutton(view: View){
            toSend="00000000"
            OutputSTRM.write(toSend.toByteArray())
        }

}

