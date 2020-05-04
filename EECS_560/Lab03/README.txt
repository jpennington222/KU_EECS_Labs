To compile the program, type "make" then enter.

To run the program type "./Lab03 data.txt" then enter.

The sample file should be formatted in the following example:

                      json, kuit560
                      java, eng2020
                      python, kuit560
                      nodejs, cls334
                      angula, lang99
                      hadoop, bgdt564
                      spark, onl345
                      csharp, pwd3456

Follow the on-screen instructions to execute the program.

The tables are initialized with a size of 11.

Before inserting a record, the program will check the load factor.

The tables will be rehashed when then load factor is > 0.5.

  Example of when rehashing is required (checking before inserting):
  json, kuit560 (load factor = 0/11)
  java, eng2020 (load factor = 1/11)
  python, kuit560 (load factor = 2/11)
  nodejs, cls334 (load factor = 3/11)
  angula, lang99 (load factor = 4/11)
  hadoop, bgdt564 (load factor = 5/11)
  spark, onl345 (load factor = 6/11, rehash before inserting)
  csharp, pwd3456 (load factor = 7/23)

When initially reading in the data from "data.txt" the table may be rehashed
depending upon how many entries are entered. If using the sample data provided,
the tables will be rehashed one time from size 11 to size 23 when attempting to add
the 7th entry (spark, onl345).

When rehasing, the entries in the table are processed sequentially.

When adding a user, type the username, then enter, then the password, then enter.

When removing a user, type the username, then enter, then the password, then enter.

Username: String (of length not more than 6 and greater than 1). Only lower case letters are allowed.

Password: Alphanumeric. A combination of characters and numbers of length not more than 7
          (at least 3 characters and at least 2 numbers). Only lower case letters are allowed.
          No special characters(for example : ., * ,   ? ,@ ,#, etc.) are allowed.

The user will be told if the username or password is invalid.
