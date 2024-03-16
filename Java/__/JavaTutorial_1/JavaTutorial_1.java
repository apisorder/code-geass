
//  tell java interpreter to make this class available to all other classes
public class JavaTutorial_1
//  class is a blueprint for our program
{
    //  class variable, accessible to all other varaiables and methods within the class
    static String randomString = "a random string";

    //  varaible that will always stay the same; or constant
    static final double PINUM = 3.141529;
    // static -> only a class can call it
    
    public static void main(String[] args)
    //  main function is required in every program we will ever write
    //  any main function must accept an array of String objects
    {
        System.out.println( "Hello World" );
        
        //  declaration statement
        int integerOne = 22;
        //  expression statement
        int integerTwo 
        = 
        integerOne 
        + 1;

        //  java doesn't care about whitespace

        //  primitive types -> differences = what values they can hold
        byte bigByte = 127;
        short bigShort = 32767;
        int bigInt = 2100000000;
        long bigLong = 9220000000000000000L;
        float bigFloat = 3.14F;

        //  double is a bigger, more precise float
        double bigDouble = 3.14823794872734872347923748;

        System.out.println(randomString);
        System.out.println(PINUM);

        //  these are system dependent
        //  precise to about 6 significant places
        System.out.println(Float.MAX_VALUE);
        //  precise to about 15 decimal places
        System.out.println(Double.MAX_VALUE);

        boolean trueOrFalse = true;

        char randomChar = 65;
        char anotherChar = 'A';

        String randomString2 =  "I'm another random string!";
        String anotherString = "Stuff";
        
        String andAnotherString = randomString2 + ' ' + anotherString;

        String byteString = Byte.toString(bigByte);
        String shortString = Short.toString(bigByte);
        String intString = Integer.toString(bigByte);
        String longString = Long.toString(bigByte);
        String floatString = Float.toString(bigByte);
        String doubleString = Double.toString(bigByte);

        int stringToInt = Integer.parseInt(intString);

        System.out.println(randomChar);
        System.out.println(anotherChar);
        System.out.println(byteString);
        System.out.println(stringToInt);
    }
}