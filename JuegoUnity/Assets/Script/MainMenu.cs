using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using System.Threading;

public class MainMenu : MonoBehaviour
{
    public BoolValue init;
    public Button imagenError;
    public string sceneToLoad;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    public void NewGame() 
    {
        client.instance.ConnectToServer();
        Thread.Sleep(2000);
        client.instance.send("1");
        SceneManager.LoadScene(sceneToLoad);

    }

    public void aceptar() 
    {
        imagenError.gameObject.SetActive(false);
        Application.Quit();
    }

    public void Exit() 
    {
        Application.Quit();
    }
}
