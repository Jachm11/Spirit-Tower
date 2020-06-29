﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Net;
using System.Net.Sockets;
using System.ComponentModel;
using System;
using System.Text;

public class client : MonoBehaviour
{
    public static client instance;
    public static int MAX_BUFFER_SIZE = 49152;

    public string ip = "127.0.0.1";
    public int port = 54010;
    public TCP tcp;

    private void Awake()
    {
        if (instance == null)
        {
            instance = this;
        }
        else if(instance != this)
        {
            Destroy(this);
        }
    }

    private void Start()
    {
        tcp = new TCP();
    }

    public void ConnectToServer()
    {
        tcp.Connect();
    }

    public string send(string msg)
    {
        string res = tcp.sendMsg(msg);
        return res;
    }

    public class TCP 
    {
        public TcpClient socket;

        private NetworkStream stream;
        private string msg;
        private byte[] buffer;

        void onDestroy()
        {
            if (socket.Connected)
            {
                socket.Close();
            }
                
        }

        public void Connect()
        {
            socket = new TcpClient
            {
                ReceiveBufferSize = MAX_BUFFER_SIZE,
                SendBufferSize = MAX_BUFFER_SIZE
            };
            buffer = new byte[MAX_BUFFER_SIZE];

            socket.BeginConnect(instance.ip, instance.port, ConnectCallback, socket);

        }

        private void ConnectCallback(IAsyncResult result)
        {
           socket.EndConnect(result);

            if (!socket.Connected)
            {
                return;
            }
            stream = socket.GetStream();

            stream.BeginRead(buffer, 0, MAX_BUFFER_SIZE, Message_Received, null);
        }

        private void Message_Received(IAsyncResult result)
        {
            if (result.IsCompleted && socket.Connected)
            {
                int bytesIn = stream.EndRead(result);
                msg = Encoding.ASCII.GetString(buffer, 0, bytesIn);
                //UnityEngine.Debug.Log(msg);
            }
        }


        public string sendMsg(string msg)
        {
            byte[] newMsg = Encoding.ASCII.GetBytes(msg);
            stream.Write(newMsg, 0, newMsg.Length);
            stream.BeginRead(buffer, 0, MAX_BUFFER_SIZE, Message_Received, null);
            return this.msg;
        }

    }

}
