using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class PtsTextManager : MonoBehaviour
{
    public Inventory playerInventory;
    public TextMeshProUGUI ptsDisplay;

    public void UpdatePtsCount() 
    {
        ptsDisplay.text = "" + playerInventory.puntos;
    }
}
