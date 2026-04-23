---
layout: page
title: Dashboard
permalink: /dashboard/
---

<style>
  .dashboard-container {
    display: flex;
    flex-direction: column;
    align-items: center;
    padding: 20px;
  }
  .dashboard-title {
    font-size: 1.5em;
    margin-bottom: 15px;
    color: #2c3e50;
  }
  .dashboard-frame {
    width: 100%;
    max-width: 1400px;
    height: 800px;
    border: 2px solid #ddd;
    border-radius: 8px;
    box-shadow: 0 4px 6px rgba(0,0,0,0.1);
  }
  .dashboard-link {
    margin-top: 15px;
    padding: 10px 20px;
    background-color: #3498db;
    color: white;
    text-decoration: none;
    border-radius: 5px;
    transition: background-color 0.3s;
  }
  .dashboard-link:hover {
    background-color: #2980b9;
  }
  .info-text {
    margin-top: 15px;
    color: #666;
    font-size: 0.9em;
  }
</style>

<div class="dashboard-container">
  <h2 class="dashboard-title">Egonaldi Bero Indizea - Denbora Errealeko Dashboard</h2>
  
  <iframe 
    src="https://eu.thingsboard.cloud/dashboard/b4a992a0-398d-11f1-ba44-c54ab1d7f1f4?publicId=ebbac470-3d80-11f1-92f7-cbbd42e0f134" 
    class="dashboard-frame"
    loading="lazy">
  </iframe>
  
  <a href="https://eu.thingsboard.cloud/dashboard/b4a992a0-398d-11f1-ba44-c54ab1d7f1f4?publicId=ebbac470-3d80-11f1-92f7-cbbd42e0f134" 
     target="_blank" 
     class="dashboard-link">
    Ireki beste fitxategian
  </a>
  
  <p class="info-text">
    Dashboard hau ThingsBoard platforman dago eta ESP8266 NodeMCU eta DHT11 sentsoretik jasotzen ditu datuak.
  </p>
</div>