using UnityEngine;

public class GameOverCollision : MonoBehaviour
{
    void Start()
    {
    }

    void Update()
    {
    }

    private void OnTriggerEnter(Collider other) { 
        Debug.Log("Game over");
    }
}
