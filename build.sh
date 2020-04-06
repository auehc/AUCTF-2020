sudo docker build Web/web3 -t web3 && \
sudo docker build Web/web4 -t web4 && \
sudo docker run -dit -p 30023:80 --name web3 web3 && \
sudo docker run -dit -p 30024:80 --name web4 web4 && \
sudo docker-compose --compatibility up --build -d && \
echo "[+] Challenges Built"
