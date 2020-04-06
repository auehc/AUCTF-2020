Animal Crossing
--

https://gfycat.com/glassimpressivecottontail

Filter all DNS queries removing all other packets by just using the filter DNS
Export DNS queries to Packet Dissections (File > Export Packet Dissections > As Plain Text)
Use the regex query .{57}.ad.quickbrownfoxes.org to extract all the DNS queries with 57 characters before
ad.quickbrownfoxes.org

Delete the inappr records because they happened to also have 57+ characters but aren't important.

Then filter out the duplicates while retaining the order using ```awk - cat data.txt | awk '!seen[$0]++'```

Order matters, simply decoding one portion without the others will likely result in broken text. 

Base64 decode the text, which will result in:

Did you ever hear the tragedy of Darth Plagueis The Wise? I thought not. It’s not a story the Jedi would tell you. It’s a Sith legend. Darth Plagueis was a Dark Lord of the Sith, so powerful and so wise he could use the Force to influence the midichlorians to create life… **auctf{it_was_star_wars_all_along}** He had such a knowledge of the dark side that he could even keep the ones he cared about from dying. The dark side of the Force is a pathway to many abilities some consider to be unnatural. He became so powerful… the only thing he was afraid of was losing his power, which eventually, of course, he did. Unfortunately, he taught his apprentice everything he knew, then his apprentice killed him in his sleep. Ironic. He could save others from death, but 

Flag: auctf{it_was_star_wars_all_along}
