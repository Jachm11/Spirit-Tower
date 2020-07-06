using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Turret : Interactivo
{

    int cicles;
    bool isIn;
    public Vector2 facing;
    public GameObject flecha;

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
            GameObject current = Instantiate(flecha.gameObject, transform.position, Quaternion.identity);
            current.GetComponent<Arrow>().launch(facing);
            cicles = 0;
        }

        else if (playerInRange && !isIn)
        {
            //player dañar
            //
            GameObject current = Instantiate(flecha.gameObject, transform.position, Quaternion.identity);
            current.GetComponent<Arrow>().launch(facing);
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
