sudo docker build Web/web5 -t web5 && \
sudo docker build Web/web4 -t web4 && \
sudo docker run -dit -p 30025:80 --name web5 web5 && \
sudo docker run -dit -p 30024:80 --name web4 web4 && \
sudo docker-compose --compatibility up --build -d && \
echo "[+] Challenges Built"
