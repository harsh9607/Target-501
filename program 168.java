// Parser for goodbooks.com xml data returned by RESTAPI 
public class Main {

    /**
     * Parses the input text and returns a Book instance containing
     * the parsed data.
     * @param response text to be parsed
     * @return Book instance containing parsed data
     */
    public static Book parse(String response) {
        Book book = new Book();

         String title;
         String author;
         int publicationYear;
         double averageRating;
         int ratingsCount;
         String imageUrl;

         String[] values = response.replaceAll("<.*?>","\t").trim().split("\t");
        /*
         for(int i=0 ; i<values.length; i++)
         {
             System.out.println("i = " + i + " val = " + values[i]);
         }
        */

         book.setAuthor(values[22]);
         book.setTitle(values[17]);
         book.setAverageRating(Double.parseDouble(values[12]));
         book.setImageUrl(values[25]);
         book.setRatingsCount(Integer.parseInt(values[4].replaceAll(",","")));
         book.setPublicationYear(Integer.parseInt(values[8]));
        // Your code
        return book;
    }

    // write overloaded parse method with the 3 parameters response, startRule, endRule
/*
*   private String title;
    private String author;
    private int publicationYear;
    private double averageRating;
    private int ratingsCount;
    private String imageUrl;
* */

    public static void main(String[] args) {
        String response = "<work>" +
                "<id type=\"integer\">2361393</id>" +
                "<books_count type=\"integer\">813</books_count>" +
                "<ratings_count type=\"integer\">1,16,315</ratings_count>" +
                "<text_reviews_count type=\"integer\">3439</text_reviews_count>" +
                "<original_publication_year type=\"integer\">1854</original_publication_year>" +
                "<original_publication_month type=\"integer\" nil=\"true\"/>" +
                "<original_publication_day type=\"integer\" nil=\"true\"/>" +
                "<average_rating>3.79</average_rating>" +
                "<best_book type=\"Book\">" +
                "<id type=\"integer\">16902</id>" +
                "<title>Walden</title>" +
                "<author>" +
                "<id type=\"integer\">10264</id>" +
                "<name>Henry David Thoreau</name>" +
                "</author>" +
                "<image_url>" +
                "http://images.gr-assets.com/books/1465675526m/16902.jpg" +
                "</image_url>" +
                "<small_image_url>" +
                "http://images.gr-assets.com/books/1465675526s/16902.jpg" +
                "</small_image_url>" +
                "</best_book>" +
                "</work>";

        Main.parse(response);
    }
}
