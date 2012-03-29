
#include <stdio.h>
#include <assert.h>

#include <sys/types.h>

#include "card_names.h"

int show_card(u_int64_t entry) {

  switch (entry) {

  case one_hearts: printf("One of hearts.\n"); break;
  case two_hearts: printf("Two of hearts.\n"); break;
  case three_hearts: printf("Three of hearts.\n"); break;
  case four_hearts: printf("Four of hearts.\n"); break;
  case five_hearts: printf("Five of hearts.\n"); break;
  case six_hearts: printf("Six of hearts.\n"); break;
  case seven_hearts: printf("Seven of hearts.\n"); break;
  case eight_hearts: printf("Eight of hearts.\n"); break;
  case nine_hearts: printf("Nine of hearts.\n"); break;
  case jack_hearts: printf("Jack of hearts.\n"); break;
  case king_hearts: printf("King of hearts.\n"); break;
  case queen_hearts: printf("Queen of hearts.\n"); break;
  case ace_hearts: printf("Ace of hearts.\n"); break;
  case one_diamonds: printf("One of diamonds.\n"); break;
  case two_diamonds: printf("Two of diamonds.\n"); break;
  case three_diamonds: printf("Three of diamonds.\n"); break;
  case four_diamonds: printf("Four of diamonds.\n"); break;
  case five_diamonds: printf("Five of diamonds.\n"); break;
  case six_diamonds: printf("Six of diamonds.\n"); break;
  case seven_diamonds: printf("Seven of diamonds.\n"); break;
  case eight_diamonds: printf("Eight of diamonds.\n"); break;
  case nine_diamonds: printf("Nin of diamonds.\n"); break;
  case jack_diamonds: printf("Jack of diamonds.\n"); break;
  case king_diamonds: printf("King of diamonds.\n"); break;
  case queen_diamonds: printf("Queen of diamonds.\n"); break;
  case ace_diamonds: printf("Ace of diamonds.\n"); break;
  case one_clubs: printf("One of clubs.\n"); break;
  case two_clubs: printf("Two of clubs.\n"); break;
  case three_clubs: printf("Three of clubs.\n"); break;
  case four_clubs: printf("Four of clubs.\n"); break;
  case five_clubs: printf("Five of clubs.\n"); break;
  case six_clubs: printf("Six of clubs.\n"); break;
  case seven_clubs: printf("Seven of clubs.\n"); break;
  case eight_clubs: printf("Eight of clubs.\n"); break;
  case nine_clubs: printf("Nine of clubs.\n"); break;
  case jack_clubs: printf("Jack of clubs.\n"); break;
  case king_clubs: printf("King of clubs.\n"); break;
  case queen_clubs: printf("Queen of clubs.\n"); break;
  case ace_clubs: printf("Ace of clubs.\n"); break;
  case one_spades: printf("One of spades.\n"); break;
  case two_spades: printf("Two of spades.\n"); break;
  case three_spades: printf("Three of spades.\n"); break;
  case four_spades: printf("Four of spades.\n"); break;
  case five_spades: printf("Five of spades.\n"); break;
  case six_spades: printf("Six of spades.\n"); break;
  case seven_spades: printf("Seven of spades.\n"); break;
  case eight_spades: printf("Eight of spades.\n"); break;
  case nine_spades: printf("Nine of spades.\n"); break;
  case jack_spades: printf("Jack of spades.\n"); break;
  case king_spades: printf("King of spades.\n"); break;
  case queen_spades: printf("Queen of spades.\n"); break;
  case ace_spades: printf("Ace of spades.\n"); break;
  case joker1: printf("First joker.\n"); break;
  case joker2: printf("Second joker.\n"); break;
  }

  return 0;

}
