# diceware
My implementation of diceware in C!

<h2>Diceware Implementation</h2>
<p>Diceware is a form of passphrase generation. Where you build a dictionary with a key and an associated string.</br>You roll one die, or five at once and write down the numbers that you got until you have a total of five.</br> Then find the associated string with the key (the rolled numbers) you got.</p>

<h1>How to use</h2>
To generate some passphrases, pass in the associated password list and type how many words you want to have generated</br>
<code>
Would generate two words
./diceware diceware.list 2
</code>

<p>Inspiration comes from this article from threatpost</p>
<url> https://firstlook.org/theintercept/2015/03/26/passphrases-can-memorize-attackers-cant-guess/ </url> </br>
More about diceware implementation </br>
<url>http://world.std.com/~reinhold/diceware.html</url>
