# Use the built image as the base image
FROM workshop-productivity:latest

# Copy files
COPY . /app/workshop
WORKDIR /app/workshop

# Create a new user and switch to that user
RUN groupadd -g 1000 workshop && \
    useradd -u 1000 -g 1000 -ms /bin/bash workshop && \
    echo "workshop ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/workshop

USER workshop
