package assignment.user;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;
import java.util.ArrayList;


import assignment.cart.Cart;


public class UsersManager {
  private static final String BASIC_USER_ID = "User00-";
  private static final  List<User> users = new ArrayList<>();


  public boolean findUserFromDB(String userID) throws SQLException {
    
    String dbUrl = "jdbc:mysql://localhost:3306/mydatabase";
    String dbUser = System.getenv("DB_USER");
    String dbPassword = System.getenv("DB_PASSWORD");
    
    String query = "SELECT firstname, lastname FROM USERS WHERE username = ?";
    try (Connection conn = DriverManager.getConnection(dbUrl, dbUser, dbPassword);
    PreparedStatement stmt = conn.prepareStatement(query)) {
      stmt.setString(1, BASIC_USER_ID + userID); // sostituisce il primo ? nella query con l'username completo dell'utente
      ResultSet rs = stmt.executeQuery();

      return rs.next(); // true se esiste almeno una riga
      }
  }

  void addUser(User user) throws SQLException{
    if(!findUserFromDB(user.getUserID()))
      users.add(user);
  }

  void removeEmptyTitlesFromUser(User user) {
    List<String> titles = user.getTitles();
    for (int i = titles.size()-1; i >= 0; i--) {
      if (titles.get(i).isEmpty()) {
        titles.remove(i); 
      }
    }
  }

  void addCartToUser(User user, Cart cart){
    user.linkCart(cart);
  }

}
