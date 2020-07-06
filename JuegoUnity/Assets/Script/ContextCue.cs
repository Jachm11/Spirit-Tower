using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ContextCue : MonoBehaviour
{
    public GameObject contextCue;
    bool active = false;

    public void Enable()
    {
        if (!active)
        {
            contextCue.SetActive(true);
            active = true;
        }
        else
        {
            contextCue.SetActive(false);
            active = false;
        }
    }
}
