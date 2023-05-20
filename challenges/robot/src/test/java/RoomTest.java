import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertTrue;

public class RoomTest {

    @Test
    public void shouldCreate5By5Room() {
        Room newRoom = new Room(5,5);
        assertTrue(newRoom.width()==5);
        assertTrue(newRoom.length()==5);
    }
}
