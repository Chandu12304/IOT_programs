# pip install "paho-mqtt<2.0"
import paho.mqtt.client as mqtt

broker = "test.mosquitto.org"
topic = "test/simplemqtt"

pub = mqtt.Client(client_id="pub")
pub.connect(broker)
pub.publish(topic, "Hello MQTT!")
print("Published: Hello MQTT!")
pub.disconnect()
