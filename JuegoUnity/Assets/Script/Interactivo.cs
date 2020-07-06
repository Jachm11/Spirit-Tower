using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Interactivo : MonoBehaviour
{

    public Signal signal;
    public bool playerInRange;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerEnter2D (Collider2D collision)
    {
        if (collision.CompareTag("Player") && !collision.isTrigger)
        {
            signal.Raise();
            playerInRange = true;
        }
    }

    private void OnTriggerExit2D (Collider2D collision)
    {
        if (collision.CompareTag("Player") && !collision.isTrigger)
        {
            signal.Raise();
            playerInRange = false;
        }
    }

}
