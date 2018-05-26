package com.example.duchkraftu.pr

import android.content.Intent
import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.EditText
import android.widget.Toast

class TerminalActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_terminal)

    }
    fun send(view: View){

        val textView = findViewById<View>(R.id.TextInput) as EditText
        val text = textView.getText()
        val toast = Toast.makeText(this, "Sent: " + text, Toast.LENGTH_SHORT)
        toast.show()
        //send text
    }
    fun returnToMain(view: View){

        val intent = Intent(this, MainActivity::class.java)
        startActivity(intent)
    }
}
