

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String[] HardCodedTestURLs = { "http://www.google.com/path?query",
			   						  "ftp://0.0.0.0/testtesttest", 
			   						  "h3t://go.au./hello?action=edit&mode=up", 
			   						  "http://qqq/#/badpath../",
			   						  "not actually a url" };

	   
	   for (int i = 0; i < HardCodedTestURLs.length; i++) {
		   boolean result;    	 
		   try{result= urlVal.isValid(HardCodedTestURLs[i]);}
	         catch(Error e) 
		   {System.out.println(HardCodedTestURLs[i]+" caused " + e);continue;} //print URL causing errors, the error message then skip it
		   	System.out.println(HardCodedTestURLs[i]+" returned " + result); //if a result can be calculated, returned it and URL
	   }
   }

   
   public void testYourFirstPartition()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   String base = "www.google.com"; 	   
	   
	   for (int i = 0; i < testSchemes.length; i++)
	   {
		   String site = testSchemes[i].item + base;
		   boolean result;
		   try{result = urlVal.isValid(site);}
		   	catch(Error e)
		   {System.out.println(site + " Caused " +e); continue;}
		   System.out.println(site + " returned " +result + "\tExpected - " + testSchemes[i].valid);
	   }
	  
   }
   
   public void testYourSecondPartition(){
		 UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		 String base = "http://sample.";
		 
		 

		  for (int i = 0; i < testDomains.length; i++)
		   {
			   String site = base + testDomains[i].item;
			   boolean result;
			   try{result = urlVal.isValid(site);}
			   	catch(Error e)
			   {System.out.println(site + " Caused " +e); continue;}
			   System.out.println(site + " returned " +result + "\tExpected - " + testDomains[i].valid);
		   }
   }
   
   public void testYourThirdPartition()
   {
	 //You can use this function to implement your First Partition testing	   
		UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		String base = "http://www.google.com";
		
		for (int i = 0; i < testPaths.length; i++) {
			   boolean result;    
			   String site = base + testPaths[i].item;
			   try{result= urlVal.isValid(site);}
		         catch(Error e) 
			   {System.out.println(site + " caused " + e);continue;} //print URL causing errors, the error message then skip it
			   	System.out.println(site + " returned " + result); //if a result can be calculated, returned it and URL
	   }
	}
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   int schemeIndex;
	   int domainIndex;
	   int pathsIndex;
	   

	   for (schemeIndex = 0; schemeIndex < testPieces[0].length; schemeIndex++)
	   {
		   for (domainIndex = 0; domainIndex < testPieces[1].length; domainIndex++)
		   {
			   for (pathsIndex = 0; pathsIndex < testPieces[2].length; pathsIndex++)
			   {
				   ResultPair schemes = testPieces[0][schemeIndex];
				   ResultPair domains = testPieces[1][domainIndex];
				   ResultPair paths = testPieces[2][pathsIndex];
				   	String urlTest = schemes.item + "www.example." +domains.item + paths.item;
				   	boolean expected = schemes.valid && domains.valid && paths.valid;
				   	boolean result;
				   	
				   	try {result = urlVal.isValid(urlTest);}
				   		catch(Error e)
				   	{System.out.println(urlTest + " caused " + e);continue;} //print URL causing errors, the error message then skip it
				   	System.out.println(urlTest + " returned " + result + "\tExpected - " + expected); //if a result can be calculated, returned it and URL
			   }
		   }
	   }


   }
   
   ResultPair[] testSchemes = {new ResultPair("http://", true),
           new ResultPair("http:/", false),
           new ResultPair("http:", false),
           new ResultPair("http", false),
           new ResultPair("http:..", false),
           new ResultPair("", true),
           new ResultPair("ttp://", false)
   };
   
   ResultPair[] testDomains = {new ResultPair("com", true),
			 new ResultPair("org", true),
			 new ResultPair("net", true),
			 new ResultPair("int", true),
			 new ResultPair("edu", true),
			 new ResultPair("gov", true),
			 new ResultPair("mil", true),
			 new ResultPair("au", true),
			 new ResultPair("uk", true),
			 new ResultPair("fr", true),
			 new ResultPair("ca", true),
			 new ResultPair("jp", true),
			 new ResultPair("ia", false),
			 new ResultPair("hq", false),
			 new ResultPair("marcopolo", false),
			 new ResultPair("marvel", false),
			 new ResultPair("frodo", false),
			 new ResultPair("hamsandwich", false)
	 };

   ResultPair[] testPaths = {new ResultPair("/goodpath", true),
			  new ResultPair("/123abc", true),
			  new ResultPair("//", false),
			  new ResultPair("/../", false),
			  new ResultPair("/multiple/slashes", true),
			  new ResultPair("/trailingslash/", true),
			  new ResultPair("", true),
			  new ResultPair("/#", false),
			  new ResultPair("noslash", false) 
	};
   
   ResultPair[][] testPieces = {testSchemes, testDomains, testPaths};
   
   public static void main(String[] argv) {
	   UrlValidatorTest fct = new UrlValidatorTest("url test");
	   fct.testIsValid();
   }

}