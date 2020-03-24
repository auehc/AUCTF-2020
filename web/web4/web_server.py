from flask import Flask, jsonify, request,abort,render_template
import requests as r
from ftplib import FTP
from os import remove
from hashlib import sha256

app = Flask(__name__)

@app.route('/')
def index():
    data = {"status":"OK", "NOTE":"For API help visit our help page /static/help"}
    return jsonify(data)

@app.route('/api/login', methods=["POST"])
def try_login():
    if not request.json or 'username' not in request.json:
        abort(400)
    username = request.json['username']
    password = request.json.get("password","")
    login_check = {"username":username,"password":password}
    token = r.post("http://10.0.2.8/api/login_check",json=login_check).json()['token']
    r_data = {"status":"OK", "token":token}
    return jsonify(r_data)

@app.route('/static/help')
def help_page():
    return render_template("help")

@app.route('/api/login_check', methods=['POST'])
def check_creds():
    if not request.json:
        abort(400)
    try:
        ftp = FTP()
        ftp.connect("localhost",2121)
        username = request.json["username"]
        if username != "anonymous" and "password" not in request.json:
            token = None
        elif username == "anonymous":
            ftp.login()
            ftp.quit()
            sha_sum = sha256(b"%s:%s" %(username,request.json['password']))
            token = sha_sum.hexdigest()
        else:
            ftp.login(username, request.json['password'])
            ftp.quit()
            sha_sum = sha256(b"%s:%s" % (request.json['username'], request.json['password']))
            token = sha_sum.hexdigest()
        del ftp
        return jsonify({"token":token})
    except:
        del ftp
        return jsonify({"token":None})

@app.route('/api/ftp/dir', methods=['POST'])
def drop_dirs():
    if not request.json or "token" not in request.json:
        abort(403)
    ftp = FTP()
    ftp.connect("localhost",2121)
    ftp.login()
    try:
        # ftp.set_pasv(False)
        if "dir" not in request.json:
            dir_dump = ftp.nlst()
        else:
            dir_dump = ftp.nlst(request.json["dir"])
        r_data = {"status":"OK", "dir":dir_dump}
        ftp.quit()
        del ftp
        return jsonify(r_data)
    except:
        ftp.quit()
        del ftp
        return jsonify({"status":"error","msg":"operation failed"})

@app.route('/api/ftp/get_file',methods=['POST'])
def get_file():
    if not request.json or "token" not in request.json:
        abort(403)
    ftp = FTP()
    ftp.connect("localhost",2121)
    ftp.login()
    try:
        file_name = request.json["file"]
        temp = open("temp.txt","wb")
        ftp.retrbinary("RETR %s" % (file_name), temp.write)
        temp.close()
        file_data = open("temp.txt","r")
        r_data = {"status":"OK","file_data":file_data.read()}
        file_data.close()
        remove("temp.txt")
        ftp.quit()
        del ftp
        return jsonify(r_data)
    except:
        ftp.quit()
        del ftp
        return jsonify({"status":"error","msg":"Couldn't open file"})

if __name__ == "__main__":
    app.run(debug=True, host="0.0.0.0",port=80)
