using UnityEngine;

public class FollowPlayer : MonoBehaviour
{
    public GameObject player;
    private Vector3 offset = new Vector3(-1, 5, -2);

    void Start()
    {
    }

    void LateUpdate()
    {
        transform.position = player.transform.position + offset;
    }
}
