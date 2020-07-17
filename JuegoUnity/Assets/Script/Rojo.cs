using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics.Tracing;
using UnityEngine;

public class Rojo : Gris
{
    public int cicles;
    public GameObject flecha;

    public override void Chase()
    {
        speed = chaseSpeed;
        Fire();
        Vector3 temp = Vector3.MoveTowards(transform.position, blanco.position, speed * Time.deltaTime);
        ChangeAnim(temp - transform.position);
        myRigidbody.MovePosition(temp);
        cicles++;
    }
    public void Fire()
    {
        if (cicles == 100)
        {

            GameObject current = Instantiate(flecha.gameObject, transform.position, Quaternion.identity);
            current.GetComponent<Arrow>().launch(facing);
            current.GetComponent<Arrow>().launch(facing);
            cicles = 0;
            Debug.Log("Flechaa");
        }
    }
}
    