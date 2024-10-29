# unicode_map
Extract the sourcecode of the relevent encoding in order to validate the checksum of ASCII or UTF8 text strings. Relevent encoding here means any number of the versions of unicode UTF8 currently up to  unicode 16.0. The relevent encoding map was called by IBM a codepage this terminology is not in use by unicode however unicode could be seen as a single codepage for the purposes of this repository the map shall be called a "bytecode to glyph map" and bytecode because as with 7bit ASCII the encoding stores the character (seen as glyph) in 8bit (or 16bit and others).

TODO: identify the sourcecode bytecode to glyph map of the utf8 implimentation in the specific libbionic C my android runs

How to get version of UTF8 from libbionic C on android 13?
