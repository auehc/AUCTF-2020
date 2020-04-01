sudo docker stop $(sudo docker ps -aq) && sudo docker container prune -f
sudo docker run -dit -p 30023:80 --name web4 web4 && sudo docker run -dit -p 30024:80 --name web5 web5 &&  sudo docker-compose --compatibility up --build -d && echo "[+] Challenges Up" 
