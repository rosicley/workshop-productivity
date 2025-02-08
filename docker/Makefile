# Variables
IMAGE_NAME = rosicley/workshop-productivity
TAG ?= latest

# Build the Docker image
docker-build:
	@echo "Building Docker image $(IMAGE_NAME):$(TAG)..."
	docker build -t $(IMAGE_NAME):$(TAG) .

# Push the Docker image
docker-push: docker-build
	@echo "Pushing Docker image $(IMAGE_NAME):$(TAG)..."
	docker push $(IMAGE_NAME):$(TAG)

# Tag the image as latest
docker-tag-latest:
	@echo "Tagging $(IMAGE_NAME):$(TAG) as $(IMAGE_NAME):latest..."
	docker tag $(IMAGE_NAME):$(TAG) $(IMAGE_NAME):latest
	docker push $(IMAGE_NAME):latest
