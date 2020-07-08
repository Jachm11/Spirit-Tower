using System.Collections;
using System.Collections.Generic;
using UnityEditorInternal;
using UnityEngine;

public class DamageZone : Interactivo
{
    bool isIn;
    private int cicles = 0;
    // Start is called before the first frame update
    void Start()
    {

        
    }

    // Update is called once per frame
    void Update()
    {

        if (isIn && cicles == 250)
        {
            //player dañar
            //
            client.instance.send("AS");
            cicles = 0;
        }

        else if (playerInRange && !isIn)
        {
            //player dañar
            //
            client.instance.send("AS");
            isIn = true;
            cicles = 0;
        }
        else if (isIn && cicles != 250)
        {
            cicles++;
        }

        if (!playerInRange && isIn)
        {
            isIn = false;
            cicles = 0;
        }
    }
}
