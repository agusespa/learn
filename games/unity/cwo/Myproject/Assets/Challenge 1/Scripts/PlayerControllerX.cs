using UnityEngine;

public class PlayerControllerX : MonoBehaviour
{
    private float speed = 10f;
    private float rotationSpeed = 30f;
    private float verticalInput;

    void Start()
    {

    }

    void Update()
    {
        verticalInput = Input.GetAxis("Vertical");

        transform.Translate(Vector3.forward * Time.deltaTime * speed);

        transform.Rotate(Vector3.right * rotationSpeed * Time.deltaTime * verticalInput);
    }
}
