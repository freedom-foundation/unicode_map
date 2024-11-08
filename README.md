# unicode_map
Extract the sourcecode of the relevent encoding in order to validate the checksum of ASCII or UTF8 text strings. Relevent encoding here means any number of the versions of unicode UTF8 currently up to  unicode 16.0. The relevent encoding map was called by IBM a codepage this terminology is not in use by unicode however unicode could be seen as a single codepage for the purposes of this repository the map shall be called a "bytecode to glyph map" and bytecode because as with 7bit ASCII the encoding stores the character (seen as glyph) in 8bit (or 16bit and others).
<h2>TODO</h2>h2> identify the sourcecode bytecode to glyph map of the utf8 implimentation in the specific libbionic C my android runs
<h2>resources</h2>
How to get version of UTF8 from libbionic C on android 13?
I queried the mailing list here https://corp.unicode.org/pipermail/unicode/2024-November/011099.html I received no answer but about 10 pages in replies of nonsense babble which prompted me to reflect on.
for a Reference model I was given this link https://www.unicode.org/versions/Unicode16.0.0/#Components
<h3>new information I gathered from the mailing list</h2>
Perhaps the only thing I really found out by the mailing list is that one can't simply ask for sourcecode and receive the sourcecode as GPL expects: but didn't I already know this?
<h3>new info AOSP</h3>
 did a little web searching, and I think I can point you to some places 
where libbionic 
<https://android.googlesource.com/platform/bionic/+/refs/heads/main/libc> 
processes code units in UTF-8 form. The source code uses the tags "mb", 
short for "multi-byte", and "wc", short for "wide character", in the 
names of functions which operate on UTF-8 code unit data and Unicode 
scalar values respectively.  Take a look at:

function mbsnrtowcs() 
<https://android.googlesource.com/platform/bionic/+/refs/heads/main/libc/bionic/wchar.cpp#68>

function mbrtc32() 
<https://android.googlesource.com/platform/bionic/+/refs/heads/main/libc/bionic/mbrtoc32.cpp#36>

I imagine you will find these unsatisfying. They implement the UTF-8 
data conversions with no mention of either UTF-8 version or Unicode 
version. Nor do they mention glyphs, fonts, character to glyph mapping, 
or any of the other text rendering complexity which it seems you want to 
characterise.
<h3>Oren's reference models</h3>
[convert.c](https://github.com/freedom-foundation/unicode_map/blob/main/convert.c)
[Conversion_of_utf8_bytecode_to_codepoints.c](https://github.com/freedom-foundation/unicode_map/blob/main/Conversion_of_utf8_bytecode_to_codepoints.c)
<h3>reflections on my mailing list query<h3></h3> 
after asking the unicode mailing list ( the new information I gathered from the mailing list is that in liue of their confusion it is apparent there is no verifiable way to confirm the unicode standard is in place on any system ) I had supposed that you would have been able to check the sourcecode ( of an OS on a machine) for conformity to a Unicode standard. for the sourcecode of UTF-8. I come to (only further confirm) realise any checksum of even a text file is useless, of even an integrity check of a download, because there is no garuntee the UTF-8 standard is the same between systems. 
My experience with the mailing list shows the misconceptions of many. Which misconceptions should be solved by ability to speak English. Many have misconceptions about what Text is therefore I explained a continuity of data -> unicode -> glyph -> text. They incessantly argue jargon and get their thoughts and meanings lost in such nonsense none of it can be applicable or made into an application.
An example of how learning to speak English solves problems. IBM had called these codepage a natural English term for code on a page in a book. A codepage. Unicode was somehow devised as some sort of a single code solution to include all languages however as it is now Unicode literaly has about 4 codepages UTF-8, UTF-16, UTF-32, and 21bit, none of these are interoperable. So there is no universal code or single-codepage all Unicode did was add to the many IBM codepages for each language 4 more codepages, but in Unicode jargon they do not call these codepages maybe because they never printed a book. Another continuity of synonyms that they will argue Unicode is a standard the data which conforms to the standard is code so both are called Unicode data which conforms to unicode is unicode. Simply recognizing words for what they mean: code on a page is codepage, code data which is unicode is unicode, code which is bytes but can't be bits is bytecode, and code which is bits is bitcode. 
Here is one of the better English grammars I have found online [freedom-foundation/An_Advanced_English_Grammar](https://github.com/freedom-foundation/An_Advanced_English_Grammar)

The quest for this map is prompted by my maxim "the sourcecode must be known" in order to checksum text. When a checksum is used against the 'text' the exact encoding must be included without the encoding the checksum is only against an unknown or unprecise blob of data and the text produced from it could be unaccurate, unperfect or currupt in some way.
  <h3>proof of concept</h3>
  If my OS reads 101 as ABA another system could show 101 as BAB though the checksum should match because it is the same data, and yet because this is bytecode there are further multiple data possibilities to produce 101->ⁿⁿⁿ suppose 11011 and 01010: these two data files produce different checksums but should display the same output as it were intended ABA. This is to say the integrity is meant to be of the content delivered to mrreader, and when using UTF-8 a checksum cannot verify the integrity of text content. 
