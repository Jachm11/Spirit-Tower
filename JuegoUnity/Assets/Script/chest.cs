using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class chest : Interactivo
{
    public Item contents;
    public Inventory playerInventory;
    public int pts;
    public bool isOpen;
    public Signal raiseItem;
    public Signal coinSignal;
    public GameObject dialogBox;
    public Text dialogText;
    public AudioSource coinSound;
    private Animator anim;


    // Start is called before the first frame update
    void Start()
    {
        anim = GetComponent<Animator>();
        //playerInventory.puntos = 0;
        coinSignal.Raise();


    }

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space) && playerInRange)
        {
            if (!isOpen)
            {
                OpenChest();
            }
            else
            {
                ChestAlreadyOpen();
            }
        }
    }

    public void OpenChest()
    {
        dialogBox.SetActive(true);
        coinSound.Play();
        dialogText.text = (pts*10).ToString(); //Es un atributo del jugador o de UI
        playerInventory.itemActual = contents;
        client.instance.send("OCO"); //Object Chest opened
        client.instance.send("L"+pts);
        playerInventory.puntos += pts *10;
        coinSignal.Raise();
        raiseItem.Raise();
        signal.Raise();
        anim.SetBool("opened", true);

        isOpen = true;
    }

    public void ChestAlreadyOpen()
    {

        dialogBox.SetActive(false);
        raiseItem.Raise();


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
