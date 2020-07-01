using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Diagnostics;
using UnityEngine;
using UnityEngine.UI;

public class UI : MonoBehaviour
{
    public static UI instance;

    public GameObject startMenu;
    public Button send;
    public Button connect;

    private void Awake()
    {
        if (instance == null)
        {
            instance = this;
        }
        else if (instance != this)
        {
            Destroy(this);
        }
    }

    public void ConnectToServer()
    {

        client.instance.ConnectToServer();
        
    }

    public void sendMessage()
    {
        string res = client.instance.send("algo");
        UnityEngine.Debug.Log(res);
    }


}
