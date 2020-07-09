using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class chest : Interactivo
{
    public int pts;
    public bool isOpen;
    //public Signal raiseItem;
    public GameObject dialogBox; 
    public Text dialogText;
    private Animator anim;


    // Start is called before the first frame update
    void Start()
    {
        anim = GetComponent<Animator>();

        
    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space)&& playerInRange)
        {
            if (!isOpen)
            {
                //Open 
                OpenChest();
            }
            else {
                ChestAlreadyOpen();
            }
        }
    }

    public void OpenChest()
    {
        dialogBox.SetActive(true);
        dialogText.text = pts.ToString(); //Es un atributo del jugador o de UI


        // avisar a Harold que puntos fueron ganados
        client.instance.send("OCO"); //Object Chest opened

        //raiseItem.Raise();

        isOpen = true;

        signal.Raise();

        anim.SetBool("opened", true);

    }

    public void ChestAlreadyOpen() 
    {
        dialogBox.SetActive(false);
        //raiseItem.Raise();
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.CompareTag("Player") && !collision.isTrigger && !isOpen)
        {
            signal.Raise();
            playerInRange = true;
        }
    }

    private void OnTriggerExit2D(Collider2D collision)
    {
        if (collision.CompareTag("Player") && !collision.isTrigger && !isOpen)
        {
            signal.Raise();
            playerInRange = false;
        }
    }
}
