from flask import Flask, request

app = Flask(__name__)

latest_data = {
    "temperature": None,
    "humidity": None
}

@app.route("/")
def index():

    return f"""
    <h1>蜂巢监测系统</h1>

    <h2>温度: {latest_data['temperature']} ℃</h2>

    <h2>湿度: {latest_data['humidity']} %</h2>
    """

@app.route("/upload", methods=["POST"])
def upload():

    data = request.json

    latest_data["temperature"] = data.get("temperature")
    latest_data["humidity"] = data.get("humidity")

    print("收到数据:", latest_data)

    return {
        "code": 200,
        "msg": "success"
    }

if __name__ == "__main__":

    app.run(
        host="0.0.0.0",
        port=5000,
        debug=True
    )