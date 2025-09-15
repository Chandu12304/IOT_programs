import paho.mqtt.client as mqtt
import time

broker = "test.mosquitto.org"
topic = "test/simplemqtt"

def on_message(client, userdata, msg):
    print("Received:", msg.payload.decode())

sub = mqtt.Client(client_id="sub")
sub.on_message = on_message
sub.connect(broker)
sub.subscribe(topic)
sub.loop_start()

# Keep it running to receive messages
time.sleep(5)
sub.loop_stop()
sub.disconnect()
