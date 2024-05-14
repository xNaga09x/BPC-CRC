Binary Message Integrity Verification Suite

Description:

Binary Message Integrity Verification Suite is a comprehensive C++ application that combines bidimensional parity check and CRC (Cyclic Redundancy Check) functionalities. The application allows users to verify the integrity of binary messages using both bidimensional parity checks and CRC algorithms. Users can input binary strings, specify a generator polynomial, perform integrity checks, and view intermediate results.

Features:

I.Bidimensional Parity Check:
1.Users input a binary string from the keyboard, ensuring it contains a multiple of 7 binary characters.
2.The input binary message is organized into a matrix with 7 columns and a variable number of rows.
3.Parity bits are calculated for each row and column of the matrix.
4.The application displays the matrix with calculated parity bits.

II.CRC (Cyclic Redundancy Check):
1.Users input a binary string and a generator polynomial with coefficients of 0 and 1.
2.Validation checks ensure that both the message and the generator polynomial are binary, and the length of the message is greater than the number of coefficients in the generator polynomial.
3.The message is extended with zeros equal to the degree of the generator polynomial.
4.Successive XOR operations are performed between the extended message and the polynomial coefficients until the length of the resulting remainder is strictly less than the length of the coefficient string.
5.Intermediate XOR operation results are displayed.
6.Another XOR operation is performed between the extended message and the final remainder obtained, positioning the remainder below the extended message.
6.The final result is displayed.

Combined Functionality:
The application seamlessly integrates both bidimensional parity check and CRC functionalities, providing users with a comprehensive suite for binary message integrity verification.
Users can choose between bidimensional parity check or CRC, or perform both checks sequentially on the same input message.

Binary Message Integrity Verification Suite offers a powerful toolset for ensuring data integrity in binary communication systems, storage applications, and data transmission protocols. Whether used for educational purposes or in practical scenarios requiring robust data validation, the suite provides a versatile solution for binary message integrity verification.
