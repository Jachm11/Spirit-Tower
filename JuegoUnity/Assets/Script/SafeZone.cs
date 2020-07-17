using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SafeZone : Interactivo
{

    public AudioSource inSafe;
    public AudioSource outSafe;
    public Signal isSafe;
    public Signal isNotSafe;
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
            inSafe.Play();
            isSafe.Raise();
        }
        if (!playerInRange && isIn)
        {
            client.instance.send("PV");
            isIn = false;
            outSafe.Play();
            isNotSafe.Raise();
        }
    }

}
