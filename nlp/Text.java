import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.HashMap;
import java.util.Map;

public class Text {
    private static String filename = "corpus.txt";
    private static String fileContent = "";
    private static String word = "";
    private static Map<String, Integer> wordMap = new HashMap<>();

    private static void addToMap(String word) {
        wordMap.put(word, wordMap.getOrDefault(word, 0) + 1);
    }

    private static String cleanWord(String word) {
        word = word.replace(".", "");
        word = word.replace(",", "");
        word = word.replace("\"", "");
        word = word.replace("!", "");
        word = word.replace("?", "");
        word = word.replace(";", "");
        return word;
    }

    public static void main(String[] args) {
        long start = System.currentTimeMillis();

        try {
            fileContent = Files.readString(Path.of("./" + filename));
        } catch (IOException e) {
            e.printStackTrace();
        }

        for (String word : fileContent.toLowerCase().split(" ")) {
            addToMap(cleanWord(word));
        }

        long finish = System.currentTimeMillis();
        long elapsed = finish - start;
        System.out.println("Elapsed time: " + elapsed + " milliseconds");

        start = System.currentTimeMillis();

        for (char ch : fileContent.toCharArray()) {
            if (ch == ' ') {
                if (word.equals("")) {
                    continue;
                } else {
                    addToMap(cleanWord(word));
                    word = "";
                }
            } else if (".,\"?!:;".contains(String.valueOf(ch))) {
                continue;
            } else {
                word += Character.toLowerCase(ch);
            }
        }

        finish = System.currentTimeMillis();
        elapsed = finish - start;
        System.out.println("Elapsed time: " + elapsed + " milliseconds");

        // implement sorting of hashmap
        // for (int i = 0; i < 10; i++) {
        //     System.out.println(entry.getKey() + ": " + entry.getValue());
        // }
    }
}

