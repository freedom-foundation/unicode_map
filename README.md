# unicode_map
Extract the sourcecode of the relevent encoding in order to validate the checksum of ASCII or UTF8 text strings. Relevent encoding here means any number of the versions of unicode UTF8 currently up to  unicode 16.0. The relevent encoding map was called by IBM a codepage this terminology is not in use by unicode however unicode could be seen as a single codepage for the purposes of this repository the map shall be called a "bytecode to glyph map" and bytecode because as with 7bit ASCII the encoding stores the character (seen as glyph) in 8bit (or 16bit and others).
<h1>UTF-8 is a problem.</h1>
Actually I have no desire for Unicode UTF-8. I was pulled into this because it happens to be what my machine uses. AOSP uses libbionic which only has UTF-8 available as a locale. - I wouldn't need to ask (Where a scalar snake is hiding?) [ in the OS sourcecode ] . ( https://corp.unicode.org/pipermail/unicode/2024-November/011139.html )
 We would probably be better off without UTF-8 it is more like a shim or [slim-jim] was added ontop of ASCII to interfere with it. ( https://corp.unicode.org/pipermail/unicode/2024-November/011117.html )

<h2>TODO</h2> Identify ( locate, bookmark ) the sourcecode- bytecode to glyph map, of the UTF-8 implimentation in the specific libbionic C my android runs. Prerequisit: this requires a readable browsable copy of the sourcecode yet importing AOSP into GitHub has failed [android-main-import](https://github.com/freedom-foundation/android-main-import)
prerequisit: also requires proprietary REPO tool
<h2>resources</h2>
Originating concise yet full though simple one line relevent ontopic question: 

Where to get the sourcecode of relevent (version) UTF-8?: in order to checksum text against the specific encoding map (codepage).

 I queried the mailing list here ( https://corp.unicode.org/pipermail/unicode/2024-November/011099.html ) begun Sat Nov 2 19:42:46 CDT 2024 25 replies from 12 senders. Notice they all instantly pose arguments and personal attacks against me whilst babbling on with conflicting, scattered, and wrong technical jargon. (https://corp.unicode.org/pipermail/unicode/2024-November/011144.html)
 
 I received no answer but about 10 pages in replies of nonsense babble which prompted me to reflect on. "focus on the originating question" Yet, 

" with about 18 pages of replies it is getting hard to track and some mail I couldn't even find before replying, " [ phantom email ] ( https://corp.unicode.org/pipermail/unicode/2024-November/011139.html )

For a Reference model I was given this link https://www.unicode.org/versions/Unicode16.0.0/#Components

<h3>new information I gathered from the mailing list</h2>
Perhaps the only thing I really found out by the mailing list is that one can't simply ask for sourcecode and receive the sourcecode as GPL expects: but didn't I already know this? Many of these may be developed into genuine cases for Letters of Marque and reprisal. 

<h4>Letters of marque and reprisal</h4>
Here is a prime example of a genuine case for reprisal. "It should be but one doesn't really know because when any buy an android phone it does not come with the sourcecode required to comply with GNU GPL and if one asks they would only point at AOSP on Google's website as if that was compliance: it is not. As I said in a previous post "with slight assumption" that the source on Google's site was used to build my machine." ( https://corp.unicode.org/pipermail/unicode/2024-November/011139.html ) This is a prime example of a gunuine case for Letter of reprisal. Another example of a genuine case for Marque is the [Google Chrome for android Criminal espionage bug](https://github.com/users/freedom-foundation/projects/2) .

<h3>Best answer</h3> a pointer into where the Unicode standard may be inside AOSP sourcecode. 
[Jim D.] did a little web searching, and I think I can point you to some places 
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
<h3>Hints</h3>
Hint: " I recommend you to look existing implementations: PGP (and GPG) protocol 
may give some hints on securely doing checksum of text." ( giacomo )
<br>
Option: [Reverse engineering](https://en.m.wikipedia.org/wiki/Reverse_engineering) Unicode. A best option shown from the mailing list  ( https://corp.unicode.org/pipermail/unicode/2024-November/011118.html )
<h3>Reflections on my mailing list query</h3> 
Awe... this is rather sad . look at them on the unicode mailing list speaking out handicapped thoughts and portraying it as English- they restrict true meanings of English to conform to their handicapped and unperfect concepts.
After asking the unicode mailing list ( the new information I gathered from the mailing list is that in liue of their confusion it is apparent there is no verifiable way to confirm the unicode standard is in place on any system ) I had supposed that you would have been able to check the sourcecode ( of an OS on a machine) for conformity to a Unicode standard. for the sourcecode of UTF-8. I come to (only further confirm) realise any checksum of even a text file is useless, of even an integrity check of a download, because there is no garuntee the UTF-8 standard is the same between systems. 
My experience with the mailing list shows the misconceptions of many. Which misconceptions should be solved by ability to speak [English](https://github.com/freedom-foundation/An_Advanced_English_Grammar). Many have misconceptions about what Text is therefore I explained a continuity of data -> unicode -> glyph -> text. 

"You guys have these fragmented thoughts and misconceptions. There is a full continuity where all of these be synonymous. data which is unicode-data which is bytecode which is an C integer which is an character may be a letter which is a glyph which is text. There is a full continuity where these are all in specific instances synonymous though not all backward compatible as a hierarchy. This is to say when Mr. Reader is reading the screen he sees TEXT. That text is consituted and comprised of all of these synonyms. Which are synonyms where they converge (instance) to comprise TEXT on Mr. Reader's screen." ( https://corp.unicode.org/pipermail/unicode/2024-November/011139.html )

They incessantly argue jargon and get their thoughts and meanings lost in such nonsense none of it can be applicable or made into an application.
An example of how learning to speak English solves problems. IBM had called these codepage a natural English term for code on a page in a book. A codepage. Unicode was somehow devised as some sort of a single code solution to include all languages however as it is now Unicode literaly has about 4 codepages UTF-8, UTF-16, UTF-32, and 21bit, none of these are interoperable. So there is no universal code or single-codepage all Unicode did was add to the many IBM codepages for each language 4 more multi-language codepages, but in Unicode jargon they do not call these codepages maybe because they never printed a book. "  goes to show that Unicode consortium is disappointed. You will probably read in there somewhere that it intended to solve a problem of many codepages hower you see that it has become something more complicated than the problem it were to simplify to solve." (https://corp.unicode.org/pipermail/unicode/2024-November/011144.html) Another continuity of synonyms that they will argue Unicode is a standard the data which conforms to the standard is code so both are called Unicode data which conforms to unicode is unicode. Simply recognizing words for what they mean: code on a page is codepage, code data which is unicode is unicode, code which is bytes but can't be bits is bytecode, and code which is bits is bitcode. 
Here is one of the better English grammars I have found online [freedom-foundation/An_Advanced_English_Grammar](https://github.com/freedom-foundation/An_Advanced_English_Grammar)

The quest for this map is prompted by my maxim "the sourcecode must be known" in order to checksum text. When a checksum is used against the 'text' the exact encoding must be included without the encoding the checksum is only against an unknown or unprecise blob of data and the text produced from it could be unaccurate, unperfect or currupt in some way.
  <h3>Proof of Concept</h3>
  If my OS reads 101 as ABA another system could show 101 as BAB though the checksum should match because it is the same data, and yet because this is bytecode there are further multiple data possibilities to produce 101->ⁿⁿⁿ suppose 11011 and 01010: these two data files produce different checksums but should display the same output as it were intended ABA. This is to say the integrity is meant to be of the content delivered to mrreader, and when using UTF-8 a checksum cannot verify the integrity of text content. 
<h5>My Maxim</h5>
  Thus My Maxim is: [for] the full circle of authentication of a checksummed text. In order to fully authenticate: the codepage of the character to glyph map must be known. ( https://corp.unicode.org/pipermail/unicode/2024-November/011102.html )
  <h5>more</h5>The 7-bit ASCII should be perfect for use-case "checksum text". -  A cyclic redundancy continuum on ASCII 7-bit text having the codepage included is simple enough and undeniably verifiable. ( https://corp.unicode.org/pipermail/unicode/2024-November/011139.html )
