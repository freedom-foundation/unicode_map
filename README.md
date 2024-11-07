# unicode_map
Extract the sourcecode of the relevent encoding in order to validate the checksum of ASCII or UTF8 text strings. Relevent encoding here means any number of the versions of unicode UTF8 currently up to  unicode 16.0. The relevent encoding map was called by IBM a codepage this terminology is not in use by unicode however unicode could be seen as a single codepage for the purposes of this repository the map shall be called a "bytecode to glyph map" and bytecode because as with 7bit ASCII the encoding stores the character (seen as glyph) in 8bit (or 16bit and others).

TODO: identify the sourcecode bytecode to glyph map of the utf8 implimentation in the specific libbionic C my android runs

How to get version of UTF8 from libbionic C on android 13?
I queried the mailing list here https://corp.unicode.org/pipermail/unicode/2024-November/011099.html I received no answer but about 10 pages in replies of nonsense babble which prompted me to reflect on.

Perhaps the only thing I really found out by the mailing list is that one can't simply ask for sourcecode and receive the sourcecode as GPL expects: but didn't I already know this?

reflections on my mailing list query 
after asking the unicode mailing list ( the new information I gathered from the mailing list is that in liue of their confusion it is apparent there is no verifiable way to confirm the unicode standard is in place on any system ) I had supposed that you would have been able to check the sourcecode ( of an OS on a machine) for conformity to a Unicode standard. for the sourcecode of UTF-8. I come to realise any checksum of even a text file is useless, of even an integrity check of a download, because there is no garuntee the UTF-8 standard is the same between systems. If my OS reads 101 as ABA another system could show 101 as BAB though the checksum should match because it is the same data, and yet because this is bytecode there are further multiple data possibilities to produce 101->ⁿⁿⁿ suppose 11011 and 01010: these two data files produce different checksums but should display the same output as it were intended ABA. This is to say the integrity is meant to be of the content delivered to mrreader, and when using UTF-8 a checksum cannot verify the integrity of text content. 
