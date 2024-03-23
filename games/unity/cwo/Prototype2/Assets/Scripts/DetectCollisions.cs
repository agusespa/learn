using UnityEngine;

public class DetectCollitions : MonoBehaviour
{
    void Start()
    {
    }

    void Update()
    {
    }

    private void OnTriggerEnter(Collider other) { 
        Destroy(gameObject);
        Destroy(other.gameObject);
    }
}
