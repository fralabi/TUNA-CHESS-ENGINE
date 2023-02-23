//TEMPORARY FILE


#include <bits/stdc++.h>
#include "bitboard.hpp"

using namespace std;

// bitboard = occupancy board + attack board of opponent pieces
// square   = position of king
Bitboard kingMove(Bitboard bitboard, int square) {

    Bitboard move = 0ULL;

    Bitboard king = 0ULL;
    set_bit(king, square);

    //NORD  -> ~ranks[0]
    //SUD   -> ~ranks[7]
    //EST   -> ~files[0]
    //OVEST -> ~files[7]     

    //NORD-OVEST
    if (king >> 9 & ~files[7] & ~ranks[0] & ~bitboard) {
            move |= (king >> 9);
    }
    //NORD
    if (king >> 8 & ~ranks[0] & ~bitboard) {
            move |= (king >> 8);
    }
    //NORD-EST
    if (king >> 7 & ~files[0] & ~ranks[0] & ~bitboard) {
            move |= (king >> 7);
    }
    //OVEST
    if (king >> 1 & ~files[7] & ~bitboard) {
            move |= (king >> 1);
    }
    //EST
    if (king << 1 & ~files[0] & ~bitboard) {
            move |= (king << 1);
    }
    //SUD-OVEST
    if (king << 7 & ~files[7] & ~ranks[7] & ~bitboard) {
            move |= (king << 7);
    }
    //SUD
    if (king << 8 & ~ranks[7] & ~bitboard) {
            move |= (king << 8);
    }
    //SUD-EST
    if (king << 9 & ~files[0] & ~ranks[7] & ~bitboard) {
            move |= (king << 9);
    }

    return move;

}

Bitboard knightMove(Bitboard bitboard, int square) {

    Bitboard move = 0ULL;

    Bitboard knight = 0ULL;
    set_bit(knight, square);

    //NORD NORD OVEST
    if (knight >> 17 & ~ranks[0] & ~ranks[1] & ~files[7]) {
        move |= (knight >> 17);
    }
    //NORD NORD EST
    if (knight >> 15 & ~ranks[0] & ~ranks[1] & ~files[0]) {
        move |= (knight >> 15);
    }
    //NORD OVEST
    if (knight >> 10 & ~ranks[0] & ~files[7] & ~files[6]) {
        move |= (knight >> 10);
    }
    //NORD EST
    if (knight >> 6 & ~ranks[0] & ~files[0] & ~files[1]) {
        move |= (knight >> 6);
    }
    //SUD OVEST
    if (knight << 6 & ~ranks[7] & ~files[7] & ~files[6]) {
        move |= (knight << 6);
    }
    //SUD EST
    if (knight << 10 & ~ranks[7] & ~files[0] & ~files[1]) {
        move |= (knight << 10);
    }
    //SUD SUD OVEST
    if (knight << 15 & ~ranks[7] & ~ranks[6] & ~files[7]) {
        move |= (knight << 15);
    }
    //SUD SUD EST
    if (knight << 17 & ~ranks[7] & ~ranks[6] & ~files[0]) {
        move |= (knight << 17);
    }

    return move;
}

Bitboard pawnMove (Bitboard bitboard, Bitboard opponent, int square, int color) {
    
    Bitboard move = 0ULL;

    Bitboard pawn = 0ULL;
    set_bit(pawn, square);

    if (!color) { //WHITE

        //NORD-OVEST
        if (pawn >> 7 & ~files[0] & ~bitboard) {
            move |= (pawn >> 7 & opponent);
        }

        //NORD-EST
        if (pawn >> 9 & ~files[7] & ~bitboard){
            move |= (pawn >> 9 & opponent);
        }

        //NORD
        move |= (pawn >> 8 & ~bitboard);

        //NORD NORD if SQUARE is on 2nd RANK

        //CONTROLLO SUL FATTO CHE SIA IN SECONDA RIGA E CHE LA CASELLA DAVANTI SIA LIBERA
        if ((pawn & ranks[1]) > 0 && get_bit(bitboard, square-8) == 0) {
            move |= (pawn >> 16 & ~bitboard);
        }

    }

    else { //BLACK

        //SUD-EST
        if (pawn << 7 & ~files[0] & ~bitboard) {
            move |= (pawn << 7);
        }

        //SUD-OVEST
        if (pawn << 9 & ~files[7] & ~bitboard){
            move |= (pawn << 9);
        }

        //SUD
        move |= (pawn << 8 & ~bitboard);

        //SUD SUD if SQUARE is on 2nd RANK

        //CONTROLLO SUL FATTO CHE SIA IN SETTIMA RIGA E CHE LA CASELLA DAVANTI SIA LIBERA
        if ((pawn & ranks[6]) > 0 && get_bit(bitboard, square+8) == 0) {
            move |= (pawn << 16 & ~bitboard);
        }
    }

    return move;
}

// MASKS
Bitboard bishop_masks[64];
Bitboard rook_masks[64];

// ATTACKS
Bitboard bishop_attacks[64][512];
Bitboard rook_attacks[64][4096];


// ROOK OCCUPANCY BITS
// NUMERO DELLE CASE ATTACCATE DA UNA TORRE IN QUELLA POSIZIONE, 
// NON CONTIAMO GLI ESTREMI DI QUESTI PERCHE' NON POSSONO INTERFERIRE NEL PERCORSO

/*

                ROOK A8

   +---+---+---+---+---+---+---+---+
 8 | R | X | X | X | X | X | X |   |
   +---+---+---+---+---+---+---+---+
 7 | X |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+
 6 | X |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+
 5 | X |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+
 4 | X |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+
 3 | X |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+
 2 | X |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+
 1 |   |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+
     a   b   c   d   e   f   g   h

*/

int rook_occupancy_bits[64] = {
    12, 11, 11, 11, 11, 11, 11, 12,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    11, 10, 10, 10, 10, 10, 10, 11,
    12, 11, 11, 11, 11, 11, 11, 12
};


// BISHOP OCCUPANCY BITS
// NUMERO DELLE CASE ATTACCATE DA UN'ALFIERE IN QUELLA POSIZIONE, 
// NON CONTIAMO GLI ESTREMI DI QUESTI PERCHE' NON POSSONO INTERFERIRE NEL PERCORSO

/*

                BISHOP E4

   +---+---+---+---+---+---+---+---+
 8 |   |   |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+
 7 |   | X |   |   |   |   |   |   |
   +---+---+---+---+---+---+---+---+
 6 |   |   | X |   |   |   | X |   |
   +---+---+---+---+---+---+---+---+
 5 |   |   |   | X |   | X |   |   |
   +---+---+---+---+---+---+---+---+
 4 |   |   |   |   | B |   |   |   |
   +---+---+---+---+---+---+---+---+
 3 |   |   |   | X |   | X |   |   |
   +---+---+---+---+---+---+---+---+
 2 |   |   | X |   |   |   | X |   |
   +---+---+---+---+---+---+---+---+
 1 |   |   |   |   |   |   |   |  |
   +---+---+---+---+---+---+---+---+
     a   b   c   d   e   f   g   h

*/

int bishop_occupancy_bits[64] = {
    6, 5, 5, 5, 5, 5, 5, 6,
    5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 7, 7, 7, 7, 5, 5,
    5, 5, 7, 9, 9, 7, 5, 5,
    5, 5, 7, 9, 9, 7, 5, 5,
    5, 5, 7, 7, 7, 7, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5,
    6, 5, 5, 5, 5, 5, 5, 6
};


// MASK ROOK ATTACKS
Bitboard mask_rook_attacks(int square)
{
    // EMPTY BITBOARD
    Bitboard attacks = 0ULL;
    
    // init files & ranks
    int f, r;
    
    // init target files & ranks
    int tr = square / 8;
    int tf = square % 8;
    
    //NORD
    for (r = tr + 1; r <= 6; r++)               
        attacks |= (1ULL << (r * 8 + tf));
    //SUD
    for (r = tr - 1; r >= 1; r--) 
        attacks |= (1ULL << (r * 8 + tf));
    //EST
    for (f = tf + 1; f <= 6; f++) 
        attacks |= (1ULL << (tr * 8 + f));
    //OVEST
    for (f = tf - 1; f >= 1; f--) 
        attacks |= (1ULL << (tr * 8 + f));

    
    return attacks;
}

// MASK BISHOP ATTACKS
Bitboard mask_bishop_attacks(int square)
{
    // EMPTY BITBOARD
    Bitboard attacks = 0ULL;
    
    // init files & ranks
    int f, r;
    
    // init target files & ranks
    int tr = square / 8;
    int tf = square % 8;
    
    // NORD
    for (r = tr + 1, f = tf + 1; r <= 6 && f <= 6; r++, f++) 
        attacks |= (1ULL << (r * 8 + f));
    // SUD
    for (r = tr + 1, f = tf - 1; r <= 6 && f >= 1; r++, f--) 
        attacks |= (1ULL << (r * 8 + f));
    // EST
    for (r = tr - 1, f = tf + 1; r >= 1 && f <= 6; r--, f++) 
        attacks |= (1ULL << (r * 8 + f));
    //OVEST
    for (r = tr - 1, f = tf - 1; r >= 1 && f >= 1; r--, f--) 
        attacks |= (1ULL << (r * 8 + f));
    
    return attacks;
}


/// ----------------------------- DA CAPIRE DA ORA IN POI -----------------------------

// just a random number
unsigned int state = 1809086573;

// 32-bit number pseudo random generator
unsigned int generate_random_number()
{
	// XOR shift algorithm
	unsigned int x = state;
	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	state = x;
	return x;
}

// generate random Bitboard number
Bitboard random_U64()
{
    // init numbers to randomize
    Bitboard u1, u2, u3, u4;
    
    // randomize numbers
    u1 = (Bitboard)(generate_random_number()) & 0xFFFF;
    u2 = (Bitboard)(generate_random_number()) & 0xFFFF;
    u3 = (Bitboard)(generate_random_number()) & 0xFFFF;
    u4 = (Bitboard)(generate_random_number()) & 0xFFFF;
    
    // shuffle bits and return
    return u1 | (u2 << 16) | (u3 << 32) | (u4 << 48);
}

// get random few bits
Bitboard random_fewbits() {
    return random_U64() & random_U64() & random_U64();
}

// COUNT BITs (Brian Kernighan's way)
// CONTA BIT IN UNA BOARD
int count_bits(Bitboard bitboard) {
  // bit count
  int count = 0;
  
  // pop bits untill bitboard is empty
  while (bitboard)
  {
      // increment count
      count++;
      
      // consecutively reset least significant 1st bit
      bitboard &= bitboard - 1;
  }
  
  // return bit count
  return count;
}

//https://www.chessprogramming.org/BitScan

// get index of LS1B in bitboard
int get_ls1b_index(Bitboard bitboard) {
    // make sure bitboard is not empty
    if (bitboard != 0)
        // convert trailing zeros before LS1B to ones and count them
        return count_bits((bitboard & -bitboard) - 1);
    
    // otherwise
    else
        // return illegal index
        return -1;
}

// set occupancies
Bitboard set_occupancy(int index, int bits_in_mask, Bitboard attack_mask)
{
    // occupancy map
    Bitboard occupancy = 0ULL;
    
    // loop over the range of bits within attack mask
    for (int count = 0; count < bits_in_mask; count++)
    {
        // get LS1B index of attacks mask
        int square = get_ls1b_index(attack_mask);
        
        // pop LS1B in attack map
        pop_bit(attack_mask, square);
        
        // make sure occupancy is on board
        if (index & (1 << count))
            // populate occupancy map
            occupancy |= (1ULL << square);
    }
    
    // return occupancy map
    return occupancy;
}


// bishop attacks
Bitboard bishop_attacks_on_the_fly(int square, Bitboard block)
{
    // attack bitboard
    Bitboard attacks = 0ULL;
    
    // init files & ranks
    int f, r;
    
    // init target files & ranks
    int tr = square / 8;
    int tf = square % 8;
    
    // generate attacks
    for (r = tr + 1, f = tf + 1; r <= 7 && f <= 7; r++, f++)
    {
        attacks |= (1ULL << (r * 8 + f));
        if (block & (1ULL << (r * 8 + f))) break;
    }
    
    for (r = tr + 1, f = tf - 1; r <= 7 && f >= 0; r++, f--)
    {
        attacks |= (1ULL << (r * 8 + f));
        if (block & (1ULL << (r * 8 + f))) break;
    }
    
    for (r = tr - 1, f = tf + 1; r >= 0 && f <= 7; r--, f++)
    {
        attacks |= (1ULL << (r * 8 + f));
        if (block & (1ULL << (r * 8 + f))) break;
    }
    
    for (r = tr - 1, f = tf - 1; r >= 0 && f >= 0; r--, f--)
    {
        attacks |= (1ULL << (r * 8 + f));
        if (block & (1ULL << (r * 8 + f))) break;
    }
    
    // return attack map for bishop on a given square
    return attacks;
}

// rook attacks
Bitboard rook_attacks_on_the_fly(int square, Bitboard block)
{
    // attacks bitboard
    Bitboard attacks = 0ULL;
    
    // init files & ranks
    int f, r;
    
    // init target files & ranks
    int tr = square / 8;
    int tf = square % 8;
    
    // generate attacks
    for (r = tr + 1; r <= 7; r++)
    {
        attacks |= (1ULL << (r * 8 + tf));
        if (block & (1ULL << (r * 8 + tf))) break;
    }
    
    for (r = tr - 1; r >= 0; r--)
    {
        attacks |= (1ULL << (r * 8 + tf));
        if (block & (1ULL << (r * 8 + tf))) break;
    }
    
    for (f = tf + 1; f <= 7; f++)
    {
        attacks |= (1ULL << (tr * 8 + f));
        if (block & (1ULL << (tr * 8 + f))) break;
    }
    
    for (f = tf - 1; f >= 0; f--)
    {
        attacks |= (1ULL << (tr * 8 + f));
        if (block & (1ULL << (tr * 8 + f))) break;
    }
    
    // return attack map for bishop on a given square
    return attacks;
}


/**************************************\
        Generating magic numbers
        
\**************************************/

// find magic number
Bitboard find_magic(int square, int relevant_bits, int bishop) {
    // define occupancies array
    Bitboard occupancies[4096];

    // define attacks array
    Bitboard attacks[4096];

    // define used indicies array
    Bitboard used_attacks[4096];
    
    // mask piece attack
    Bitboard mask_attack = 1 ? mask_bishop_attacks(square) : mask_rook_attacks(square);

    // occupancy variations
    int occupancy_variations = 1 << relevant_bits;

    // loop over the number of occupancy variations
    for(int count = 0; count < occupancy_variations; count++) {
        // init occupancies
        occupancies[count] = set_occupancy(count, relevant_bits, mask_attack);
        
        // init attacks
        attacks[count] = 1 ? bishop_attacks_on_the_fly(square, occupancies[count]) :
                                  rook_attacks_on_the_fly(square, occupancies[count]);
    }

    // test magic numbers
    for(int random_count = 0; random_count < 100000000; random_count++)
    {
        // init magic number candidate
        Bitboard magic = random_fewbits();

        // skip testing magic number if inappropriate
        if(count_bits((mask_attack * magic) & 0xFF00000000000000ULL) < 6) 
          continue;

        // reset used attacks array
        memset(used_attacks, 0ULL, sizeof(used_attacks));
        
        // init count & fail flag
        int count, fail;
        
        // test magic index
        for (count = 0, fail = 0; !fail && count < occupancy_variations; count++) {
            // generate magic index
            int magic_index = (int)((occupancies[count] * magic) >> (64 - relevant_bits));
          
            // if got free index
            if(used_attacks[magic_index] == 0ULL)
                // assign corresponding attack map
                used_attacks[magic_index] = attacks[count];

            // otherwise fail on  collision
            else if(used_attacks[magic_index] != attacks[count]) fail = 1;
        }
        
        // return magic if it works
        if(!fail) return magic;
    }
    
    // on fail
    printf("***Failed***\n");
    return 0ULL;
}

// init magics
void init_magics()
{
  printf("const Bitboard rook_magics[64] = {\n");
  
  // loop over 64 board squares
  for(int square = 0; square < 64; square++)
      printf("    0x%llxULL,\n", find_magic(square, rook_occupancy_bits[square], 0));
  
  printf("};\n\nconst Bitboard bishop_magics[64] = {\n");
  
  // loop over 64 board squares
  for(int square = 0; square < 64; square++)
      printf("    0x%llxULL,\n", find_magic(square, bishop_occupancy_bits[square], 1));
  
  printf("};\n\n");
}


//HASH TABLE generato con init_magics()
const Bitboard rook_magics[64] = {
    0x8a80104000800020ULL,
    0x140002000100040ULL,
    0x2801880a0017001ULL,
    0x100081001000420ULL,
    0x200020010080420ULL,
    0x3001c0002010008ULL,
    0x8480008002000100ULL,
    0x2080088004402900ULL,
    0x800098204000ULL,
    0x2024401000200040ULL,
    0x100802000801000ULL,
    0x120800800801000ULL,
    0x208808088000400ULL,
    0x2802200800400ULL,  
    0x2200800100020080ULL,
    0x801000060821100ULL,
    0x80044006422000ULL,
    0x100808020004000ULL,
    0x12108a0010204200ULL,
    0x140848010000802ULL,
    0x481828014002800ULL,
    0x8094004002004100ULL,
    0x4010040010010802ULL,
    0x20008806104ULL,
    0x100400080208000ULL,
    0x2040002120081000ULL,
    0x21200680100081ULL,
    0x20100080080080ULL,
    0x2000a00200410ULL,
    0x20080800400ULL,
    0x80088400100102ULL,
    0x80004600042881ULL,
    0x4040008040800020ULL,
    0x440003000200801ULL,
    0x4200011004500ULL,
    0x188020010100100ULL,
    0x14800401802800ULL,
    0x2080040080800200ULL,
    0x124080204001001ULL,
    0x200046502000484ULL,
    0x480400080088020ULL,
    0x1000422010034000ULL,
    0x30200100110040ULL,
    0x100021010009ULL,
    0x2002080100110004ULL,
    0x202008004008002ULL,
    0x20020004010100ULL,
    0x2048440040820001ULL,
    0x101002200408200ULL,
    0x40802000401080ULL,
    0x4008142004410100ULL,
    0x2060820c0120200ULL,
    0x1001004080100ULL,
    0x20c020080040080ULL,
    0x2935610830022400ULL,
    0x44440041009200ULL,
    0x280001040802101ULL,
    0x2100190040002085ULL,
    0x80c0084100102001ULL,
    0x4024081001000421ULL,
    0x20030a0244872ULL,
    0x12001008414402ULL,
    0x2006104900a0804ULL,
    0x1004081002402ULL,
};

const Bitboard bishop_magics[64] = {
    0x40040844404084ULL,
    0x2004208a004208ULL,
    0x10190041080202ULL,
    0x108060845042010ULL,
    0x581104180800210ULL,
    0x2112080446200010ULL,
    0x1080820820060210ULL,
    0x3c0808410220200ULL,
    0x4050404440404ULL,
    0x21001420088ULL,
    0x24d0080801082102ULL,
    0x1020a0a020400ULL,
    0x40308200402ULL,
    0x4011002100800ULL,
    0x401484104104005ULL,
    0x801010402020200ULL,
    0x400210c3880100ULL,
    0x404022024108200ULL,
    0x810018200204102ULL,
    0x4002801a02003ULL,
    0x85040820080400ULL,
    0x810102c808880400ULL,
    0xe900410884800ULL,
    0x8002020480840102ULL,
    0x220200865090201ULL,
    0x2010100a02021202ULL,
    0x152048408022401ULL,
    0x20080002081110ULL,
    0x4001001021004000ULL,
    0x800040400a011002ULL,
    0xe4004081011002ULL,
    0x1c004001012080ULL,
    0x8004200962a00220ULL,
    0x8422100208500202ULL,
    0x2000402200300c08ULL,
    0x8646020080080080ULL,
    0x80020a0200100808ULL,
    0x2010004880111000ULL,
    0x623000a080011400ULL,
    0x42008c0340209202ULL,
    0x209188240001000ULL,
    0x400408a884001800ULL,
    0x110400a6080400ULL,
    0x1840060a44020800ULL,
    0x90080104000041ULL,
    0x201011000808101ULL,
    0x1a2208080504f080ULL,
    0x8012020600211212ULL,
    0x500861011240000ULL,
    0x180806108200800ULL,
    0x4000020e01040044ULL,
    0x300000261044000aULL,
    0x802241102020002ULL,
    0x20906061210001ULL,
    0x5a84841004010310ULL,
    0x4010801011c04ULL,
    0xa010109502200ULL,
    0x4a02012000ULL,
    0x500201010098b028ULL,
    0x8040002811040900ULL,
    0x28000010020204ULL,
    0x6000020202d0240ULL,
    0x8918844842082200ULL,
    0x4010011029020020ULL,
};

// init slider pieces attacks
void init_sliders_attacks(int is_bishop)
{
    // loop over 64 board squares
    for (int square = 0; square < 64; square++)
    {
        // init bishop & rook masks
        bishop_masks[square] = mask_bishop_attacks(square);
        rook_masks[square] = mask_rook_attacks(square);
        
        // init current mask
        Bitboard mask = is_bishop ? mask_bishop_attacks(square) : mask_rook_attacks(square);
        
        // count attack mask bits
        int bit_count = count_bits(mask);
        
        // occupancy variations count
        int occupancy_variations = 1 << bit_count;
        
        // loop over occupancy variations
        for (int count = 0; count < occupancy_variations; count++)
        {
            // bishop
            if (is_bishop)
            {
                // init occupancies, magic index & attacks
                Bitboard occupancy = set_occupancy(count, bit_count, mask);
                Bitboard magic_index = occupancy * bishop_magics[square] >> 64 - bishop_occupancy_bits[square];
                bishop_attacks[square][magic_index] = bishop_attacks_on_the_fly(square, occupancy);                
            }
            
            // rook
            else
            {
                // init occupancies, magic index & attacks
                Bitboard occupancy = set_occupancy(count, bit_count, mask);
                Bitboard magic_index = occupancy * rook_magics[square] >> 64 - rook_occupancy_bits[square];
                rook_attacks[square][magic_index] = rook_attacks_on_the_fly(square, occupancy);                
            }
        }
    }
}

// lookup bishop attacks 
Bitboard get_bishop_attacks(int square, Bitboard occupancy) {
	
	// calculate magic index
	occupancy &= bishop_masks[square];
	occupancy *=  bishop_magics[square];
	occupancy >>= 64 - bishop_occupancy_bits[square];
	
	// return rellevant attacks
	return bishop_attacks[square][occupancy];
	
}

// lookup rook attacks 
Bitboard get_rook_attacks(int square, Bitboard occupancy) {
	
	// calculate magic index
	occupancy &= rook_masks[square];
	occupancy *=  rook_magics[square];
	occupancy >>= 64 - rook_occupancy_bits[square];
	
	// return rellevant attacks
	return rook_attacks[square][occupancy];
}

enum { 
  whitePawn, 
  blackPawn, 
  knight, 
  bishop, 
  rook, 
  queen, 
  whiteKing,
  blackKing
};

const int pieceChessBoardValue [8][64] =
{
// PAWN (WHITE)
{
  0,   0,   0,   0,   0,   0,   0,   0,
100, 100, 100, 100, 100, 100, 100, 100,
 50,  50,  50,  50,  50,  50,  50,  50,
 20,  20,  20,  20,  20,  20,  20,  20,
 10,  10,  10,  10,  10,  10,  10,  10,
 10,  10,  10,  10,  10,  10,  10,  10,
  5,   5,   5,   5,   5,   5,   5,   5,
  0,   0,   0,   0,   0,   0,   0,   0
},
// PAWN (BLACK)
{
  0,   0,   0,   0,   0,   0,   0,   0,
  5,   5,   5,   5,   5,   5,   5,   5,
 10,  10,  10,  10,  10,  10,  10,  10,
 10,  10,  10,  10,  10,  10,  10,  10,
 20,  20,  20,  20,  20,  20,  20,  20,
 50,  50,  50,  50,  50,  50,  50,  50,
100, 100, 100, 100, 100, 100, 100, 100,
  0,   0,   0,   0,   0,   0,   0,   0
},
// KNIGHT
{
-120, -120, -120, -120, -120, -120, -120, -120,
-120,   75,   75,   75,   75,   75,   75, -120,
-120,   75,  150,  150,  150,  150,   75, -120,
-120,   75,  150,  300,  300,  150,   75, -120,
-120,   75,  150,  300,  300,  150,   75, -120,
-120,   75,  150,  150,  150,  150,   75, -120,
-120,   75,   75,   75,   75,   75,   75, -120,
-120, -120, -120, -120, -120, -120, -120, -120
},
// BISHOP
{
-40, -40,  -40,  -40,  -40,  -40, -40, -40,
-40,  70,   70,   70,   70,   70,  70, -40,
-40,  70,  120,  120,  120,  120,  70, -40,
-40,  70,  120,  170,  170,  120,  70, -40,
-40,  70,  120,  170,  170,  120,  70, -40,
-40,  70,  120,  120,  120,  120,  70, -40,
-40,  70,   70,   70,   70,   70,  70, -40,
-40, -40,  -40,  -40,  -40,  -40, -40, -40
},
// ROOK
{
0, 50, 100, 150, 150, 100, 50, 0,
50, 50, 100, 150, 150, 100, 50, 50,
50, 50, 100, 150, 150, 100, 50, 50,
50, 50, 100, 150, 150, 100, 50, 50,
50, 50, 100, 150, 150, 100, 50, 50,
50, 50, 100, 150, 150, 100, 50, 50,
50, 50, 100, 150, 150, 100, 50, 50,
0, 50, 100, 150, 150, 100, 50, 0
},
// QUEEN
{
250,  250, 250,  250,  250, 250, 250, 250,
250,  500, 500,  500,  500, 500, 500, 250,
250,  500, 750,  750,  750, 750, 500, 250,
250,  500, 750, 1000, 1000, 750, 500, 250,
250,  500, 750, 1000, 1000, 750, 500, 250,
250,  500, 750,  750,  750, 750, 500, 250,
250,  500, 500,  500,  500, 500, 500, 250,
250,  250, 250,  250,  250, 250, 250, 250
},
// KING (WHITE)
{
-900, -900, -900, -900, -900, -900, -900, -900,
-900, -900, -900, -900, -900, -900, -900, -900,
-900, -900, -900, -900, -900, -900, -900, -900,
-900, -900, -900, -900, -900, -900, -900, -900,
-900, -900, -900, -900, -900, -900, -900, -900,
-700, -700, -700, -700, -700, -700, -700, -700,
-200, -200, -500, -500, -500, -500, -200, -200,
 200,  300,  100, -300,  300,  100,  300,  200
},
// KING (BLACK)
{
 200,  300,  100, -300,  300,  100,  300,  200
-200, -200, -500, -500, -500, -500, -200, -200,
-700, -700, -700, -700, -700, -700, -700, -700,
-900, -900, -900, -900, -900, -900, -900, -900,
-900, -900, -900, -900, -900, -900, -900, -900,
-900, -900, -900, -900, -900, -900, -900, -900,
-900, -900, -900, -900, -900, -900, -900, -900,
-900, -900, -900, -900, -900, -900, -900, -900
}
// KING (ENDGAME)
/*
{
  0,  30, 50, 200,  200,  50,  30,   0,
 30,  50, 100, 300, 300, 100,  50,  30,
 50, 100, 200, 400, 400, 200, 100,  50,
200, 300, 400, 500, 500, 400, 300, 200,
200, 300, 400, 500, 500, 400, 300, 200,
 50, 100, 200, 400, 400, 200, 100,  50,
 30,  50, 100, 300, 300, 100,  50,  30,
  0,  30,  50, 200, 200,  50,  30,   0
}
*/
};

/*
const int pieceChessBoardValueEndGame [7][64] =
{
// PAWN (WHITE)
{
  0,  0,  0,  0,  0,  0,  0,  0,
 10, 10, 10, 10, 10, 10, 10, 10,
  5,  5,  5,  5,  5,  5,  5,  5,
  2,  2,  2,  2,  2,  2,  2,  2,
  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0
},
// PAWN (BLACK)
{
 0,  0,  0,  0,  0,  0,  0,  0,
 0,  0,  0,  0,  0,  0,  0,  0,
 0,  0,  0,  0,  0,  0,  0,  0,
 0,  0,  0,  0,  0,  0,  0,  0,
 2,  2,  2,  2,  2,  2,  2,  2,
 5,  5,  5,  5,  5,  5,  5,  5,
10, 10, 10, 10, 10, 10, 10, 10,
 0,  0,  0,  0,  0,  0,  0,  0
},
// KNIGHT
{
-120, -120, -120, -120, -120, -120, -120, -120,
-120,   25,   25,   25,   25,   25,   25, -120,
-120,   25,   50,   50,   50,   50,   25, -120,
-120,   25,   50,  100,  100,   50,   25, -120,
-120,   25,   50,  100,  100,   50,   25, -120,
-120,   25,   50,   50,   50,   50,   25, -120,
-120,   25,   25,   25,   25,   25,   25, -120,
-120, -120, -120, -120, -120, -120, -120, -120
},
// BISHOP
{
-40, -40, -40, -40, -40, -40, -40, -40,
-40,  20,  20,  20,  20,  20,  20, -40,
-40,  20,  30,  30,  30,  30,  20, -40,
-40,  20,  30,  45,  45,  30,  20, -40,
-40,  20,  30,  45,  45,  30,  20, -40,
-40,  20,  30,  30,  30,  30,  20, -40,
-40,  20,  20,  20,  20,  20,  20, -40,
-40, -40, -40, -40, -40, -40, -40, -40
},
// ROOK
{
0, 0, 10, 15, 15, 10, 0, 0,
0, 0, 10, 15, 15, 10, 0, 0,
0, 0, 10, 15, 15, 10, 0, 0,
0, 0, 10, 15, 15, 10, 0, 0,
0, 0, 10, 15, 15, 10, 0, 0,
0, 0, 10, 15, 15, 10, 0, 0,
0, 0, 10, 15, 15, 10, 0, 0,
0, 0, 10, 15, 15, 10, 0, 0
},
// QUEEN
{
0,  0,  0,  0,    0,  0, 0, 0,
0,  0,  0,  0,    0,  0, 0, 0,
0,  0, 75,  75,  75, 75, 0, 0,
0,  0, 75, 200, 200, 75, 0, 0,
0,  0, 75, 200, 200, 75, 0, 0,
0,  0, 75,  75,  75, 75, 0, 0,
0,  0,  0,   0,   0,  0, 0, 0,
0,  0,  0,   0,   0,  0, 0, 0
},
// KING
{
  0,  30, 50, 200,  200,  50,  30,   0,
 30,  50, 100, 300, 300, 100,  50,  30,
 50, 100, 200, 400, 400, 200, 100,  50,
200, 300, 400, 500, 500, 400, 300, 200,
200, 300, 400, 500, 500, 400, 300, 200,
 50, 100, 200, 400, 400, 200, 100,  50,
 30,  50, 100, 300, 300, 100,  50,  30,
  0,  30,  50, 200, 200,  50,  30,   0
}
};*/

//VALUTAZIONE OGGETTIVA DELLA POSIZIONE INDIPENDENTEMENTE DA CHI HA LA MOSSA
int evaluate (ChessBoard chessboard) {
  int white=0, black=0;

  //WHITE
  for (int i=8; i<=55; i++) {
    if(get_bit(chessboard.WhitePawns,i) > 0) {
      white += pieceChessBoardValue[whitePawn][i];
    }
  }
  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhiteRooks,i) > 0) {
      white += pieceChessBoardValue[rook][i];
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhiteBishops,i) > 0) {
      white += pieceChessBoardValue[bishop][i];
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhiteKnights,i) > 0) {
      white += pieceChessBoardValue[knight][i];
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhiteQueens,i) > 0) {
      white += pieceChessBoardValue[queen][i];
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.WhiteKing,i) > 0) {
      white += pieceChessBoardValue[whiteKing][i];
    }
  }

  //BLACK
  for (int i=8; i<=55; i++) {
    if(get_bit(chessboard.BlackPawns,i) > 0) {
      black += pieceChessBoardValue[blackPawn][i];
    }
  }
  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.BlackRooks,i) > 0) {
      black += pieceChessBoardValue[rook][i];
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.BlackBishops,i) > 0) {
      black += pieceChessBoardValue[bishop][i];
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.BlackKnights,i) > 0) {
      black += pieceChessBoardValue[knight][i];
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.BlackQueens,i) > 0) {
      black += pieceChessBoardValue[queen][i];
    }
  }

  for (int i=0; i<=63; i++) {
    if(get_bit(chessboard.BlackKing,i) > 0) {
      black += pieceChessBoardValue[blackKing][i];
    }
  }

  return white-black;
  
}

