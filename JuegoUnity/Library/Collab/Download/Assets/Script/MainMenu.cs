using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

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
        try
        {
            client.instance.ConnectToServer();
            string res = client.instance.send("prueba");
            if (res != "El servidor esta lleno, intentelo mas tarde")
            {
                client.instance.send("1");
                SceneManager.LoadScene(sceneToLoad);
            }
        }
        catch
        {
            imagenError.gameObject.SetActive(true);
        }
        
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
