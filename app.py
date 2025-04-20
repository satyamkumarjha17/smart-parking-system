from flask import Flask, render_template, jsonify, request

app = Flask(__name__)

capacity = 20
parked_cars = []

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/park', methods=['POST'])
def park_car():
    car_plate = request.json.get('car_plate')

    if car_plate in parked_cars:
        return jsonify({'message': 'Car is already parked!'}), 400

    if len(parked_cars) < capacity:
        parked_cars.append(car_plate)
        return jsonify({'message': f'Car {car_plate} parked successfully!'}), 200
    else:
        return jsonify({'message': 'Parking lot full!'}), 400

@app.route('/remove', methods=['POST'])
def remove_car():
    if parked_cars:
        car_plate = parked_cars.pop()
        return jsonify({'message': f'Car {car_plate} removed successfully!'}), 200
    else:
        return jsonify({'message': 'No cars to remove!'}), 400

@app.route('/status', methods=['GET'])
def status():
    # Reverse the list to show most recently parked car at the top
    return jsonify({'parked': list(reversed(parked_cars))})

if __name__ == '__main__':
    app.run(debug=True, port=5001)
