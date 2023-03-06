# IMAP:

Internet Message Access Protocol is a protocol designed to retrieve email from mail servers.
It has some advantages over POP3 such as the ability to dynamically view messages as they arrive in real-time unlike the latter that only downloads messages and then cuts off the connection.

## Connecting:

To connect to the gmail imap server we issue the following command

```openssl s_client -crlf -connect imap.gmail.com:993```

![Alt text](../screens/2.png?raw=true "Demo")

## Logging in:


```tag login user@gmail.com password```

Instead of using your actual password you're supposed to generate a token and login with it
https://myaccount.google.com/apppasswords

![Alt text](../screens/3.png?raw=true "Demo")

## Navigating:

This command lists all mailboxes:

```tag LIST "" "*"```

This command shows some metadata about the inbox mail box:

```tag SELECT INBOX```

To show the number of messages inbox has type the following command:

```tag STATUS INBOX (MESSAGES)```

To show the headers of a range of messages issue the following command:

```tag FETCH minRange:maxRange (BODY[HEADER])```

![Alt text](../screens/4.png?raw=true "Demo")

To access a certain message issue the following command supplied by its number:

```tag FETCH NUM (BODY)```

![Alt text](../screens/5.png?raw=true "Demo")

Messages are divided into many parts so in order to access those parts the following command is to be typed:

```tag FETCH NUM (BODY[n])```

# HTTP/Telnet:

Hypertext Transfer protocol is the protocol carrying the web since the dawn of the internet. At its inception, it was meant transfer documents around the science/research community's networks
but nowadays we use it for much more.
From what I know telnet is the unsecure predecessor to SSH.
It was also used to access Bulletin Board Systems (BBS) which were like chatrooms of the dinosaur age from what I understand.
But nowadays they use it to debug network services which is similar to what we're going to do in this exercise.

Connect to youtube.com through the port 80

```telnet youtube 80```

Make an HTTP 1.1 GET request supplied by the path you want to make a request to which is "/" in our case

```GET / HTTP/1.1```

![Alt text](../screens/6.png?raw=true "Demo")