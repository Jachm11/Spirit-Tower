using System.Collections;
using System.Collections.Generic;
using UnityEditor.Rendering.LookDev;
using UnityEngine;

public class SafeZone : Interactivo
{
    bool isIn;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (playerInRange && !isIn)
        {
            //player hacer invisible
            client.instance.send("PI");
            isIn = true;
        }
        if (!playerInRange && isIn)
        {
            client.instance.send("PV");
            isIn = false;
        }
    }

}
