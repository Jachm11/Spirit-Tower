using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class FinishMenu : MonoBehaviour
{
    public Text estadisiticas;
    private bool enviado = true;
    // Start is called before the first frame update

    private void Awake()
    {
        GameObject.FindGameObjectWithTag("Music").GetComponent<AudioManager>().StopBoss();
        GameObject.FindGameObjectWithTag("Music").GetComponent<AudioManager>().playVictory();

    }
    void Start()
    {
       
    }


    // Update is called once per frame
    void Update()
    {
        recuest();
    }
    private void recuest()
    {
        if (enviado)
        {
            string est = client.instance.send("END");
            estadisiticas.text = est;
            enviado = false;
        }
    }
    public void goBack()
    {
        SceneManager.LoadScene("StartMenu");
    }
}
