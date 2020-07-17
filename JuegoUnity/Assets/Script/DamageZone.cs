using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DamageZone : Interactivo
{
    bool isIn;
    private int cicles = 0;
    public FloatValue playerHealth;
    public FloatValue heartContainers;
    public float amountToDecrease;

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
            playerHealth.RuntimeValue -= amountToDecrease;
            client.instance.send("AS");
            if (playerHealth.initialValue > heartContainers.RuntimeValue)
            {
                playerHealth.initialValue = heartContainers.RuntimeValue;
            }
            cicles = 0;
        }

        else if (playerInRange && !isIn)
        {
            //player dañar
            playerHealth.RuntimeValue -= amountToDecrease;
            client.instance.send("AS");
            if (playerHealth.initialValue > heartContainers.RuntimeValue)
            {
                playerHealth.initialValue = heartContainers.RuntimeValue;
            }
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
