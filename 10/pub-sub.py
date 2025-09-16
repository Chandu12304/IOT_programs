# pip install paho-mqtt
import time
import paho.mqtt.client as mqtt

def on_msg(client, userdata, message):
    print(f"Received Message: {message.payload.decode()}")

client = mqtt.Client()
client.on_message = on_msg
client.connect("Broker.Hivemq.com")
client.subscribe("topic/test")
client.loop_start()
i=0
while True:
    client.publish("topic/test",f"Test Ping {i}")
    i=i+1
    time.sleep(1)
