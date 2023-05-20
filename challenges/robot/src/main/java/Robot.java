public class Robot {

    private final String name;

    private int xPosition;

    private int yPosition;

    private int orientation;

    private int crashes;

    private final Room roomMap;

    public Robot(String name, int xPosition, int yPosition, int orientation, Room room) {
        this.name = name;
        this.xPosition = xPosition;
        this.yPosition = yPosition;
        this.orientation = orientation;
        this.crashes = 0;
        this.roomMap = room;
    }

    public void executeCommand(String command) {
        for (char c : command.toLowerCase().toCharArray()) {
            if (c == 'f') moveForward();
            else if (c == 'l' || c == 'r') changeOrientation(c);
            else throw new IllegalArgumentException("invalid command");
        }
    }

    void changeOrientation(char direction) {
        int newOrientation = switch (direction) {
            case 'l' -> orientation - 1;
            case 'r' -> orientation + 1;
            default -> orientation;
        };
        if (newOrientation == 5) orientation = 1;
        else if (newOrientation == 0) orientation = 4;
        else orientation = newOrientation;
    }

    void moveForward() {
        switch (orientation) {
            case 1 -> {
                if (yPosition > 0) yPosition -= 1;
                else crashes += 1;
            }
            case 2 -> {
                if (xPosition < roomMap.width()-1) xPosition += 1;
                else crashes += 1;
            }
            case 3 -> {
                if (yPosition < roomMap.length()-1) yPosition += 1;
                else crashes += 1;
            }
            case 4 -> {
                if (xPosition > 0) xPosition -= 1;
                else crashes += 1;
            }
        }
    }

    char getOrientation() {
        return switch (orientation) {
            case 1 -> 'N';
            case 2 -> 'E';
            case 3 -> 'S';
            case 4 -> 'W';
            default -> '?';
        };
    }

    public String getReport() {
        return name + "'s final position: " + xPosition + " " + yPosition + " " + getOrientation() + " (" + crashes + " crashes)";
    }

    public String getName() {
        return name;
    }
}
