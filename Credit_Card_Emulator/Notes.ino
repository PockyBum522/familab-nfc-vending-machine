  //POLARITY DOES NOT MATTER ON PINS 10 and 11

 /*** Track 2 Layout: ***

   | SS |  PAN  | FS |  Additional Data  | ES | LRC |

 SS=Start Sentinel ";"
 PAN=Primary Acct. # (19 digits max)
 FS=Field Separator "="
 Additional Data=Expiration Date, offset, encrypted PIN, etc.
 ES=End Sentinel "?"
 LRC=Longitudinal Redundancy Check 
 */
  
  /*
  Figure 6:        ANSI/ISO BCD Data Format

  * Remember that b1 (bit #1) is the LSB (least significant bit)!
  * The LSB is read FIRST!
  * Hexadecimal conversions of the Data Bits are given in parenthesis (xH).

        --Data Bits--   Parity
        b1  b2  b3  b4   b5    Character  Function

        0   0   0   0    1        0 (0H)    Data
        1   0   0   0    0        1 (1H)      "
        0   1   0   0    0        2 (2H)      "
        1   1   0   0    1        3 (3H)      "
        0   0   1   0    0        4 (4H)      "
        1   0   1   0    1        5 (5H)      "
        0   1   1   0    1        6 (6H)      "
        1   1   1   0    0        7 (7H)      "
        0   0   0   1    0        8 (8H)      "
        1   0   0   1    1        9 (9H)      "
        0   1   0   1    1        : (AH)    Control
        1   1   0   1    0        ; (BH)    Start Sentinel
        0   0   1   1    1        < (CH)    Control
        1   0   1   1    0        = (DH)    Field Separator
        0   1   1   1    0        > (EH)    Control
        1   1   1   1    1        ? (FH)    End Sentinel


           ***** 16 Character 5-bit Set *****
                10 Numeric Data Characters
                3 Framing/Field Characters
                3 Control Characters
  */
  
 // ;1111222233334444=9912101xxxxxxxxxxxxx? // Visa string format
