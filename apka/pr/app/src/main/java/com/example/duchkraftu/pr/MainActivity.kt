package com.example.duchkraftu.pr

import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.*

class MainActivity : AppCompatActivity() {

    val OnItemClick = AdapterView.OnItemClickListener {
        parent, view: View,position: Int, id: Long ->
        val text = parent.getItemAtPosition(position).toString()
        val toast= Toast.makeText(this, text, Toast.LENGTH_SHORT)
        toast.show()
        val intent = Intent(this, TerminalActivity::class.java)
        startActivity(intent)
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val lv = findViewById<View>(R.id.LV) as ListView
        val devices = arrayOf("a", "b", "c")
        val array_adapter = ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, devices)
        lv.setAdapter(array_adapter)
        lv.setOnItemClickListener(OnItemClick)

    }
}

