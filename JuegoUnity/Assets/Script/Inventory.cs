using System.Collections;
using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu]
public class Inventory : ScriptableObject, ISerializationCallbackReceiver
{
    public Item itemActual;
    public int initialPts;

    [HideInInspector]
    public float puntos;

    public void OnAfterDeserialize()
    {
        puntos = initialPts;
    }

    public void OnBeforeSerialize() { }

}
