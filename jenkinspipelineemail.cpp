pipeline {
    agent any
    environment {
        SRC_DIR = "DIRECTORY_PATH"
        TEST_ENV = "TESTING_ENVIRONMENT"
        PROD_ENV = "Agam"
    }
    stages {
        stage('Build') {
            steps {
                echo "Fetching the source code from ${SRC_DIR}"
                echo "Compiling the code and generating artifacts"
                echo "The code is built using the build automation tool Jeremy"
            }
        }

        stage('Unit and Integration Tests') {
            steps {
                echo "Running unit tests"
                echo "Executing integration tests"
                echo "Jeremy used the automation tool"
            }
            post {
                success {
                    mail to: "agamagarwal83@gmail.com",
                         subject: "Test Status Email",
                         body: "Tests are completed successfully"
                }
            }
        }

        stage('Code Analysis') {
            steps {
                echo "Checking the quality of the code"
                echo "SonarQube is used for code analysis"
            }
        }

        stage('Security Scan') {
            steps {
                echo "Performing security scan with VeraCode"
            }
            post {
                success {
                    mail to: "agamagarwal83@gmail.com",
                         subject: "Security Scan Status: ${currentBuild.result}",
                         body: "Security scan completed successfully"
                }
            }
        }

        stage('Deploy to Staging') {
            steps {
                echo "Deploying the application to the staging server using Jenkins"
            }
        }

        stage('Integration Tests on Staging') {
            steps {
                echo "Running integration tests on the staging environment to ensure the application functions as expected in a production-like environment"
            }
        }

        stage('Deploy to Production') {
            steps {
                echo "Deploying the code to the production environment: ${PROD_ENV}"
                echo "Deploying the application to the production server"
            }
        }
    }
}
